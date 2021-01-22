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

void test_socket_send(int argc, char* argv[]) {
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

  if(connect(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0){
      printf("connet failed!\n");
  }else{
      char *nomal_data = "123";
      char *oob_data = "abd";
      send(sockfd, nomal_data, sizeof(nomal_data), 0);
      send(sockfd, nomal_data, sizeof(oob_data), MSG_OOB);
      send(sockfd, nomal_data, sizeof(nomal_data), 0);
  }

  close(sockfd);
  return;
}

int main(int argc, char* argv[]) {
  test_socket_send(argc, argv);
  return 0;
}