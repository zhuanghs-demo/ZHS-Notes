#include <arpa/inet.h>
#include <assert.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 512

void visit_daytime(int argc, char* argv[]) {
  assert(argc == 2);
  char* host = argv[1];
  //获取目标主机地址信息
  struct hostent* hostinfo = gethostbyname(host);
  assert(hostinfo);
  //获取daytime服务信息
  struct servent* servinfo = getservbyname("daytime", "tcp");
  assert(servinfo);
  printf("daytime port is %d\n", ntohs(servinfo->s_port));

  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_port = servinfo->s_port;
  address.sin_addr = *(struct in_addr*)*hostinfo->h_addr_list;
  char ip[INET_ADDRSTRLEN];
  inet_ntop(AF_INET, &address.sin_addr, ip, INET_ADDRSTRLEN);
  printf("ip is: %s\n", ip);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  int ret = connect(sockfd, (struct sockaddr*)&address, sizeof(address));
  assert(ret != -1);

  char buff[128];
  ret = read(sockfd, buff, sizeof(buff));
  assert(ret > 0);
  buff[ret] = '\0';
  printf("the daytime is: %s\n", buff);
  close(sockfd);

  return;
}

int main(int argc, char* argv[]) {
  visit_daytime(argc, argv);
  return 0;
}