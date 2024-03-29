#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_EVENT_NUMBER 1024
static int pipefd[2];

int setnoblocking(int fd) {
  int old_option = fcntl(fd, F_GETFL);
  int new_option = old_option | O_NONBLOCK;
  fcntl(fd, F_SETFL, new_option);
  return old_option;
}

void addfd(int epollfd, int fd) {
  epoll_event event;
  event.data.fd = fd;
  event.events = EPOLLIN | EPOLLET;
  epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
  setnoblocking(fd);
}

void sig_handler(int sig) {
  int save_errno = errno;
  int msg = sig;
  send(pipefd[1], (char*)&msg, 1, 0);
  errno = save_errno;
}

void addsig(int sig) {
  struct sigaction sa;
  memset(&sa, '\0', sizeof(sa));
  sa.sa_handler = sig_handler;
  sa.sa_flags |= SA_RESTART;
  sigfillset(&sa.sa_mask);
  assert(sigaction(sig, &sa, NULL) != -1);
}

void unified_event(int argc, char* argv[]) {
  if (argc < 2) {
    printf("usage : %s ip_address port_number\n", basename(argv[0]));
    return;
  }

  printf("start\n");
  const char* ip = argv[1];
  int port = atoi(argv[2]);

  //创建TCPsocket
  struct sockaddr_in address;
  bzero(&address, sizeof(address));
  address.sin_family = AF_INET;
  inet_pton(AF_INET, ip, &address.sin_addr);
  address.sin_port = htons(port);

  int listenfd = socket(PF_INET, SOCK_STREAM, 0);
  assert(listenfd >= 0);

  int ret = bind(listenfd, (struct sockaddr*)&address, sizeof(address));
  assert(ret != -1);

  ret = listen(listenfd, 5);
  assert(ret != -1);

  //注册可读事件
  epoll_event events[MAX_EVENT_NUMBER];
  int epollfd = epoll_create(5);
  assert(epollfd != -1);
  addfd(epollfd, listenfd);

  //创建socket管道并注册
  ret = socketpair(PF_UNIX, SOCK_STREAM, 0, pipefd);
  assert(ret != -1);
  setnoblocking(pipefd[1]);
  addfd(epollfd, pipefd[0]);

  addsig(SIGHUP);
  addsig(SIGCHLD);
  addsig(SIGTERM);
  addsig(SIGINT);
  bool stop_server = false;

  while (!stop_server) {
    int number = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
    if ((number < 0) && (errno != EINTR)) {
      printf("epoll failure\n");
      break;
    }
    for (int i = 0; i < number; ++i) {
      int sockfd = events[i].data.fd;
      unsigned eventbit = events[i].events;
      if (sockfd == listenfd) {
        struct sockaddr_in client_address;
        socklen_t client_length = sizeof(client_address);
        int connfd =
            accept(sockfd, (struct sockaddr*)&client_address, &client_length);
        assert(connfd >= 0);
        addfd(epollfd, connfd);
      } else if ((sockfd == pipefd[0]) && (eventbit & EPOLLIN)) {
        int sig;
        char signals[1024];
        ret = recv(pipefd[0], &signals, sizeof(signals), 0);
        if (ret == -1) {
          continue;
        } else if (ret == 0) {
          continue;
        } else {
          for (int j = 0; j < ret; ++j) {
            switch (signals[j]) {
              case SIGCHLD:
              case SIGHUP:
                continue;
              case SIGTERM:
              case SIGINT:
                stop_server = true;
            }
          }
        }
      } else {
        printf("something else happened\n");
      }
    }
  }
  printf("close fds\n");
  close(pipefd[0]);
  close(pipefd[1]);
  close(listenfd);
  return;
}

int main(int argc, char* argv[]) {
  unified_event(argc, argv);
  return 0;
}