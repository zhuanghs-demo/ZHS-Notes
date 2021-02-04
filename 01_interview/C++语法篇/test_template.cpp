/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2021-02-04 16:10:51
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2021-02-04 16:55:53
 */
#include <string.h>

#include <iostream>

template <unsigned M, unsigned N>
int compare(const char (&c1)[M], const char (&c2)[N]) {
  return strcmp(c1, c2);
}

int main() {
  std::cout << compare("hi", "com") << std::endl;
  return 0;
}