/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-12-17 09:59:24
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2021-01-09 16:14:25
 */
#include <arpa/inet.h>
#include <bits/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

void byteorder() {
  union {
    short value;
    char union_bytes[sizeof(short)];
  } test;
  test.value = 0x0102;
  if (test.union_bytes[0] == 1 && test.union_bytes[1] == 2) {
    printf("big endian\n");
  } else if (test.union_bytes[0] == 2 && test.union_bytes[1] == 1) {
    printf("little endian\n");
  } else {
    printf("unknown\n");
  }
}

void test_inet_ntoa() {
  struct in_addr in1;
  in1.s_addr = 0xffffffff;
  struct in_addr in2;
  in2.s_addr = 0x0100007f;
  char* szValue1 = inet_ntoa(in1);
  char* szValue2 = inet_ntoa(in2);
  printf("address 1: %s\n", szValue1);
  printf("address 2: %s\n", szValue2);
  return;
}

void test_inet_pton() {
  char* ipSrc = "127.0.0.1";
  void* ipDst = malloc(sizeof(struct in_addr));
  if (!ipDst) return;
  int ret = inet_pton(AF_INET, ipSrc, ipDst);
  if (ret) printf("net address: %#010X", *((int*)ipDst));
  return;
}

void main() {
  byteorder();
  test_inet_ntoa();
  test_inet_pton();
  return;
}