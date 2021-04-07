#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void socket_sendfile(int argc, char* argv[]) {
  if (argc <= 3) {
    printf("usage : %s ip_address port_number filename\n", basename(argv[0]));
    return;
  }

  printf("start\n");
  const char* ip = argv[1];
  int port = atoi(argv[2]);
  const char* file_name = argv[3];

  int filefd = open(file_name, O_RDONLY);
  assert(filefd > 0);
  struct stat file_stat;
  fstat(filefd, &file_stat);

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

  struct sockaddr_in client;
  socklen_t client_addrlength = sizeof(client);
  int connfd = accept(sockfd, (struct sockaddr*)&client, &client_addrlength);
  if (connfd < 0) {
    printf("error : %s\n", strerror(errno));
  } else {
    sendfile(connfd, filefd, NULL, file_stat.st_size);
    close(connfd);
  }
  close(sockfd);
  return;
}

int main(int argc, char* argv[]) {
  socket_sendfile(argc, argv);
  return 0;
}