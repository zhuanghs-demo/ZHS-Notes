#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

void set_send_buffer(int argc, char* argv[]) {
  if (argc <= 2) {
    printf("usage : %s ip_address port_number\n", basename(argv[0]));
    return;
  }

  printf("start\n");
  const char* ip = argv[1];
  int port = atoi(argv[2]);

  struct sockaddr_in server_address;
  bzero(&server_address, sizeof(server_address));
  server_address.sin_family = AF_INET;
  inet_pton(AF_INET, ip, &server_address.sin_addr);
  server_address.sin_port = htons(port);

  int sockfd = socket(PF_INET, SOCK_STREAM, 0);
  assert(sockfd >= 0);

  int sendbuf = atoi(argv[3]);
  int len = sizeof(sendbuf);

  /*先设置TCP发送缓冲区的大小，然后立刻读取之*/
  setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &sendbuf, len);
  getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &sendbuf, (socklen_t*)&len);

  if(connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0){
      printf("connet failed!\n");
  }else{
      char buff[BUFFER_SIZE];
      memset(buff, 'a', BUFFER_SIZE);
      send(sockfd, buff, BUFFER_SIZE, 0);
  }

  close(sockfd);
  return;
}

int main(int argc, char* argv[]) {
  set_send_buffer(argc, argv);
  return 0;
}