/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2021-02-04 16:10:51
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2021-02-05 09:38:30
 */
#include <string.h>

#include <iostream>

template <unsigned M, unsigned N>
int compare(const char (&c1)[M], const char (&c2)[N]) {
  return strcmp(c1, c2);
}

template <unsigned N>
struct Fibo {
  const static int res = Fibo<N - 1>::res + Fibo<N - 2>::res;
};

template <>
struct Fibo<1> {
  const static int res = 1;
};

template <>
struct Fibo<0> {
  const static int res = 0;
};

int main() {
  std::cout << compare("hi", "com") << std::endl;
  std::cout << Fibo<20>::res << std::endl;
  return 0;
}
