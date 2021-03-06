#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024

void set_recv_buffer(int argc, char* argv[]) {
  if (argc < 2) {
    printf("usage : %s ip_address port_number\n", basename(argv[0]));
    return;
  }

  printf("start\n");
  const char* ip = argv[1];
  int port = atoi(argv[2]);

  struct sockaddr_in address;
  bzero(&address, sizeof(address));
  address.sin_family = AF_INET;
  inet_pton(AF_INET, ip, &address.sin_addr);
  address.sin_port = htons(port);

  int sockfd = socket(PF_INET, SOCK_STREAM, 0);
  assert(sockfd >= 0);

  int revbuf = atoi(argv[3]);
  int len = sizeof(revbuf);
  /*先设置TCP发送缓冲区的大小，然后立刻读取之*/
  setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &revbuf, len);
  getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &revbuf, (socklen_t*)&len);
  printf("the tcp recevice buffer size after setting is %d \n", revbuf);

  int ret = bind(sockfd, (struct sockaddr*)&address, sizeof(address));
  assert(ret != -1);

  ret = listen(sockfd, 5);
  assert(ret != -1);

  struct sockaddr_in client;
  socklen_t client_addrlength = sizeof(client);
  int connfd = accept(sockfd, (struct sockaddr*)&client, &client_addrlength);
  if (connfd < 0) {
    printf("error : %s\n", strerror(errno));
  } else {
    char buffer[BUF_SIZE];
    memset(buffer, '\0', BUF_SIZE);
    ret = recv(connfd, buffer, BUF_SIZE-1, 0);
    while(ret > 0){
      printf("recevice data: %s, data len: %d\n", buffer, sizeof(buffer));
    }
    close(connfd);
  }
  close(sockfd);
  return;
}

int main(int argc, char* argv[]) {
  set_recv_buffer(argc, argv);
  return 0;
}