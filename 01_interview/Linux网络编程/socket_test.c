/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-12-17 09:59:24
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-12-17 10:09:42
 */
#include <stdio.h>

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

void main() {
  byteorder();
  return;
}