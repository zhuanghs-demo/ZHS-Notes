/*
 * @Descripttion: stack
 * @version: V1.00
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-09-22 11:19:25
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-23 16:54:25
 */
#include "../02_MyList/mylist.h"

template <typename T>
class myStack : public myList<T> {
 public:
  void push(const T& e) { this->insertAsLast(e); }
  T pop() { return this->remove(this->last()); }
  T& top() { return this->last()->data; }
};
