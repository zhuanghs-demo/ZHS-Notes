/*
 * @Author: Allen zhuang
 * @Date: 2021-02-04 16:04:50
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2021-07-21 00:33:56
 */

#include <string.h>

#include <iostream>
#include <type_traits>

template <unsigned M, unsigned N>
int compare(const char (&c1)[M], const char (&c2)[N]) {
  return strcmp(c1, c2);
}

template <typename RT, typename T1, typename T2>
RT max(T1 a, T2 b) {
  return a > b ? a : b;
}

template <typename T1, typename T2>
auto max1(T1 a, T2 b)
    -> decltype(a > b ? a : b) {  // since C++11 can not deal reference type
  return a > b ? a : b;
}

template <typename T1, typename T2>
auto max2(T1 a, T2 b)
    -> decltype(true ? a : b) {  // since C++11 can not deal reference type
  return a > b ? a : b;
}

template <typename T1, typename T2>
auto max3(T1 a, T2 b) ->
    typename std::decay<decltype(true ? a : b)>::type {  // since C++11
  return a > b ? a : b;
}

template <typename T1, typename T2>
typename std::common_type<T1, T2>::type max4(T1 a, T2 b) {  // since C++11
  return a > b ? a : b;
}

template <typename T1, typename T2>
std::common_type<T1, T2> max5(T1 a, T2 b) {  // since C++14
  return a > b ? a : b;
}

template <
    typename T1,
    typename T2,
    typename RT = std::decay_t<decltype(true ? T1() : T2())>>  // since C++11
RT max6(T1 a, T2 b) {
  return a > b ? a : b;
}

template <typename T1,
          typename T2,
          typename RT = std::common_type<T1, T2>>  // since C++14
RT max7(T1 a, T2 b) {
  return a > b ? a : b;
}

template <typename RT = long, typename T1, typename T2>  // since C++11
RT max8(T1 a, T2 b) {
  return a > b ? a : b;
}
