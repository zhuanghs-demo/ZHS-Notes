/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2021-02-03 16:46:22
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2021-02-03 17:31:17
 */
#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

//定义两种HTTP状态码和状态信息
static const char* status_line[2] = {"200 OK", "500 Internal server error"};

void https_reply(int argc, char* argv[]) {
  if (argc <= 3) {
    printf("usage : %s ip_address port_number filename\n", basename(argv[0]));
    return;
  }

  printf("start\n");
  const char* ip = argv[1];
  int port = atoi(argv[2]);
  //将目标文件作为第三个参数传入
  const char* file_name = argv[3];

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
    /*用于保存HTTP应答的状态行、头部字段和一个空行的缓存区*/
    char header_buf[BUFFER_SIZE];
    memset(header_buf, '\0', BUFFER_SIZE);
    /*用于存放目标文件内容的应用程序缓存*/
    char* file_buf;
    /*用于获取目标文件的属性，比如是否为目录，文件大小等*/
    struct stat file_stat;
    /*记录目标文件是否为有效文件*/
    bool vaild = true;
    /*缓存区header_buf目前已使用的字节空间*/
    int len = 0;
    if (stat(file_name, &file_stat) < 0) {
      vaild = false;
    } else {
      if (S_ISDIR(file_stat.st_mode)) {
        vaild = false;
      } else if (file_stat.st_mode & S_IROTH) {
        int fd = open(file_name, O_RDONLY);
        file_buf = new char[file_stat.st_size + 1];
        memset(file_buf, '\0', file_stat.st_size + 1);
        if (read(fd, file_buf, file_stat.st_size) < 0) {
          vaild = false;
        }
      } else {
        vaild = false;
      }
    }
    /*如果目标文件有效，则发送正常的HTTP应答*/
    if (vaild) {
      ret = snprintf(header_buf, BUFFER_SIZE - 1, "%s %s\r\n", "HTTP/1.1",
                     status_line[0]);
      len += ret;
      ret = snprintf(header_buf + len, BUFFER_SIZE - 1 - len,
                     "Content-Length: %d\r\n", file_stat.st_mode);
      len += ret;
      ret = snprintf(header_buf + len, BUFFER_SIZE - 1 - len, "%s", "\r\n");
      struct iovec iv[2];
      iv[0].iov_base = header_buf;
      iv[0].iov_len = strlen(header_buf);
      iv[1].iov_base = file_buf;
      iv[1].iov_len = file_stat.st_size;
      ret = writev(connfd, iv, 2);
    } else {
      ret = snprintf(header_buf, BUFFER_SIZE - 1, "%s %s\r\n", "HTTP/1.1",
                     status_line[1]);
      len += ret;
      ret = snprintf(header_buf + len, BUFFER_SIZE - 1 - len, "%s", "\r\n");
      send(connfd, header_buf, strlen(header_buf), 0);
    }
    close(connfd);
    delete[] file_buf;
  }
  close(sockfd);
  return;
}

int main(int argc, char* argv[]) {
  https_reply(argc, argv);
  return 0;
}