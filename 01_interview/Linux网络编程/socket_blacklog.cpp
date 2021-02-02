/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2021-01-09 16:52:53
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2021-01-09 17:31:21
 */
#include <arpa/inet.h>
#include <assert.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

static bool stop = false;

static void handle_term(int sig) { stop = true; }

int main(int argc, char* argv[]) {
  signal(SIGTERM, handle_term);
  if (argc <= 3) {
    printf("usage: %s ip_address port_number backlog\n", basename(argv[0]));
    return 1;
  }
  const char* ip = argv[1];
  int port = atoi(argv[2]);
  int backlog = atoi(argv[3]);

  // create socket
  int sockfd = socket(PF_INET, SOCK_STREAM, 0);
  assert(sockfd >= 0);

  // create socket address
  struct sockaddr_in address;
  bzero(&address, sizeof(address));
  address.sin_family = AF_INET;
  inet_pton(AF_INET, ip, &address.sin_addr);
  address.sin_port = htons(port);

  // bind the socket
  int ret = bind(sockfd, (struct sockaddr*)&address, sizeof(address));
  assert(ret != -1);

  // listen
  ret = listen(sockfd, backlog);
  assert(ret != -1);

  while (!stop) {
    sleep(1);
  }

  close(sockfd);
  return 0;
}