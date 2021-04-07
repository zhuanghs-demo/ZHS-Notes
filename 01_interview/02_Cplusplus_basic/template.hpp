/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2021-02-04 16:04:50
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2021-02-04 16:55:40
 */

#include <string.h>

#include <iostream>

template <unsigned M, unsigned N>
int compare(const char (&c1)[M], const char (&c2)[N]) {
  return strcmp(c1, c2);
}