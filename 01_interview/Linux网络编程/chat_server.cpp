/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2021-02-05 11:41:03
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2021-02-05 16:47:19
 */
#define _GNU_SOURCE 1
#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <poll.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define USER_LIMIT 5    //最大用户数量
#define BUFFER_SIZE 64  //读缓冲区的大小
#define FD_LIMIT 65535  //文件描述符数量限制

//客户数据：客户端socket地址，待写到客户端数据的位置，从客户端读入的数据
struct client_data {
  struct sockaddr_in address;
  char* write_buf;
  char buf[BUFFER_SIZE];
};

int setnonblocking(int fd) {
  int old_opition = fcntl(fd, F_GETFL);
  int new_opition = old_opition | O_NONBLOCK;
  fcntl(fd, F_SETFL, new_opition);
  return old_opition;
}

void chat_server(int argc, char* argv[]) {
  if (argc < 2) {
    printf("usage : %s ip_address port_number\n", basename(argv[0]));
    return;
  }
  const char* ip = argv[1];
  int port = atoi(argv[2]);

  int ret = 0;
  struct sockaddr_in address;
  bzero(&address, sizeof(address));
  address.sin_family = AF_INET;
  inet_pton(AF_INET, ip, &address.sin_addr);
  address.sin_port = htons(port);

  int listenfd = socket(PF_INET, SOCK_STREAM, 0);
  assert(listenfd >= 0);

  ret = bind(listenfd, (struct sockaddr*)&address, sizeof(address));
  assert(ret != -1);

  ret = listen(listenfd, 5);
  assert(ret != -1);

  client_data* users = new client_data[USER_LIMIT];
  pollfd fds[USER_LIMIT + 1];
  int user_counter = 0;
  for (int i = 1; i <= USER_LIMIT; ++i) {
    fds[i].fd = 0;
    fds[i].events = 0;
  }
  fds[0].fd = listenfd;
  fds[0].events = POLLIN | POLLERR;
  fds[0].revents = 0;

  while (1) {
    ret = poll(fds, user_counter + 1, -1);
    if (ret < 0) {
      printf("poll failure\n");
      break;
    }
    for (int i = 0; i < user_counter + 1; ++i) {
      if ((fds[i].fd == listenfd) && (fds[i].revents & POLLIN)) {
        struct sockaddr_in client_adress;
        socklen_t client_length = sizeof(client_adress);
        int connfd =
            accept(listenfd, (struct sockaddr*)&client_adress, &client_length);
        if (connfd < 0) {
          printf("errno is %d\n", errno);
          continue;
        }
        if (user_counter >= USER_LIMIT) {
          const char* info = "too many users\n";
          printf("%s\n", info);
          send(connfd, info, strlen(info), 0);
          close(connfd);
          continue;
        }
        user_counter++;
        users[connfd].address = client_adress;
        setnonblocking(connfd);
        fds[user_counter].fd = connfd;
        fds[user_counter].events = POLLIN | POLLRDHUP | POLLERR;
        fds[user_counter].revents = 0;
        printf("comes s new user, now have %d users\n", user_counter);
      }
    }
  }

  close(listenfd);
  return;
}

int main(int argc, char* argv[]) {
  chat_server(argc, argv);
  return 0;
}