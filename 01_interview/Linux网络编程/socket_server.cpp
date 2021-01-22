#include <arpa/inet.h>
#include <assert.h>
#include <endian.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024

void test_socket_recv(int argc, char* argv[]) {
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

  int ret = bind(sockfd, (struct sockaddr*)&address, sizeof(address));
  assert(ret != -1);

  ret = listen(sockfd, 5);
  assert(ret != -1);

  sleep(20);

  struct sockaddr_in client;
  socklen_t client_addrlength = sizeof(client);
  int connfd = accept(sockfd, (struct sockaddr*)&client, &client_addrlength);
  if (connfd < 0) {
    printf("error : %s\n", strerror(errno));
  } else {
    // printf("==================\n");
    // char remote[INET_ADDRSTRLEN];
    // printf("connectted with ip: %s and port: %d\n",
    //        inet_ntop(AF_INET, &client.sin_addr, remote, INET_ADDRSTRLEN),
    //        ntohs(client.sin_port));
    char buffer[BUF_SIZE];
    memset(buffer, '\0', BUF_SIZE-1);
    ret = recv(connfd, buffer, BUF_SIZE-1, 0);
    printf("got %d bytes of nomal data '%s' \n", ret, buffer);

    memset(buffer, '\0', BUF_SIZE-1);
    ret = recv(connfd, buffer, BUF_SIZE-1, MSG_OOB);
    printf("got %d bytes of nomal data '%s' \n", ret, buffer);

    memset(buffer, '\0', BUF_SIZE-1);
    ret = recv(connfd, buffer, BUF_SIZE-1, 0);
    printf("got %d bytes of nomal data '%s' \n", ret, buffer);

    close(connfd);
  }
  close(sockfd);
  return;
}

int main(int argc, char* argv[]) {
  test_socket_recv(argc, argv);
  return 0;
}