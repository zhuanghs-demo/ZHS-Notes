#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

static const int CONTROL_LEN = CMSG_LEN(sizeof(int));

void send_fd(int fd, int fd_to_send) {
  struct iovec iov[1];
  struct msghdr msg;
  char buf[1];

  iov[0].iov_base = buf;
  iov[0].iov_len = 1;
  msg.msg_name = NULL;
  msg.msg_namelen = 0;
  msg.msg_iov = iov;
  msg.msg_iovlen = 1;

  cmsghdr cm;
  cm.cmsg_len = CONTROL_LEN;
  cm.cmsg_level = SOL_SOCKET;
  cm.cmsg_type = SCM_RIGHTS;
  *(int*)CMSG_DATA(&cm) = fd_to_send;
  msg.msg_control = &cm;  //设置辅助数据
  msg.msg_controllen = CONTROL_LEN;

  sendmsg(fd, &msg, 0);
}

int recv_fd(int fd) {
  struct iovec iov[1];
  struct msghdr msg;
  char buf[1];

  iov[0].iov_base = buf;
  iov[0].iov_len = 1;
  msg.msg_name = NULL;
  msg.msg_namelen = 0;
  msg.msg_iov = iov;
  msg.msg_iovlen = 1;

  cmsghdr cm;
  msg.msg_control = &cm;
  msg.msg_controllen = CONTROL_LEN;

  recvmsg(fd, &msg, 0);

  int fd_to_read = *(int*)CMSG_DATA(&cm);
  return fd_to_read;
}

void pass_fd_between_process(int argc, char* argv[]) {
  int pipefd[2];
  int fd_to_pass = 0;
  int ret = socketpair(PF_UNIX, SOCK_DGRAM, 0, pipefd);
  assert(ret != -1);

  pid_t pid = fork();
  assert(pid >= 0);

  if (pid == 0) {
    printf("child process:%d\n", getpid());
    close(pipefd[0]);
    fd_to_pass = open("/home/other/linkMsg.log", O_RDWR, 0666);
    send_fd(pipefd[1], (fd_to_pass > 0) ? fd_to_pass : 0);
    char child_buf[2048 * 1024];
    memset(child_buf, '\0', 2048 * 1024);
    read(fd_to_pass, child_buf, 2048 * 1024);
    printf("I got fd %d and send data:\n %s\n", fd_to_pass, child_buf);
    close(fd_to_pass);
    exit(0);
  }

  printf("parent process:%d\n", getpid());
  close(pipefd[1]);
  fd_to_pass = recv_fd(pipefd[0]);
  char buf[2048 * 1024];
  memset(buf, '\0', 2048 * 1024);
  read(fd_to_pass, buf, 2048 * 1024);
  printf("I got fd %d and recv data:\n %s\n", fd_to_pass, buf);
  close(fd_to_pass);
}

int main(int argc, char* argv[]) {
  pass_fd_between_process(argc, argv);
  return 0;
}