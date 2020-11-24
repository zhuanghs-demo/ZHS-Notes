/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-24 15:32:50
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-24 15:52:42
 */

#include <iostream>
#include <stack>
#include <string>

bool isValid(std::string s) {
  std::stack<char> stk;
  int len = s.length();
  for (int i = 0; i < len; ++i) {
    switch (s[i]) {
      case '(':
      case '[':
      case '{':
        stk.push(s[i]);
        break;
      case ')': {
        if (!stk.empty() && stk.top() == '(')
          stk.pop();
        else
          stk.push(s[i]);
        break;
      }
      case ']': {
        if (!stk.empty() && stk.top() == '[')
          stk.pop();
        else
          stk.push(s[i]);
        break;
      }
      case '}': {
        if (!stk.empty() && stk.top() == '{')
          stk.pop();
        else
          stk.push(s[i]);
        break;
      }
      default:
        break;
    }
  }
  return stk.empty();
}

int main() {
  std::string s = "]";
  std::cout << isValid(s) << std::endl;
  return 0;
}