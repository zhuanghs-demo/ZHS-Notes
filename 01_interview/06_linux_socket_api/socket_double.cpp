/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2021-01-13 23:50:45
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2021-01-14 00:28:47
 */
#include <endian.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/*double类型数据网络字节序与主机字节序之间的转换*/

#define htonl64 htobe64
#define ntohl64 be64toh

uint64_t htonf64(double dValue) {
  uint64_t ulltmp = 0;
  memcpy(&ulltmp, &dValue, 8);
  ulltmp = htonl64(ulltmp);
  return ulltmp;
}

double ntohf64(uint64_t ulValue) {
  uint64_t ulltmp = 0;
  double ret = 0.0;
  ulltmp = ntohl64(ulValue);
  memcpy(&ret, &ulltmp, 8);
  return ret;
}

int main() {
  double a = 123.345;
  uint64_t b = 0;
  double c = 0.0;
  printf("a = %lf\n", a);
  b = htonf64(a);
  printf("b = %d\n", b);
  c = ntohf64(b);
  printf("c = %lf\n", c);
  printf("unsigned long:%d, unsigned long int:%d\n", sizeof(unsigned long),
         sizeof(unsigned long int));
  return 0;
}