/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-24 15:32:50
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-12-06 02:28:25
 */

// #include <iostream>
// #include <stack>
// #include <string>

// bool isValid(std::string s) {
//   std::stack<char> stk;
//   int len = s.length();
//   for (int i = 0; i < len; ++i) {
//     switch (s[i]) {
//       case '(':
//       case '[':
//       case '{':
//         stk.push(s[i]);
//         break;
//       case ')': {
//         if (!stk.empty() && stk.top() == '(')
//           stk.pop();
//         else
//           stk.push(s[i]);
//         break;
//       }
//       case ']': {
//         if (!stk.empty() && stk.top() == '[')
//           stk.pop();
//         else
//           stk.push(s[i]);
//         break;
//       }
//       case '}': {
//         if (!stk.empty() && stk.top() == '{')
//           stk.pop();
//         else
//           stk.push(s[i]);
//         break;
//       }
//       default:
//         break;
//     }
//   }
//   return stk.empty();
// }

// int main() {
//   std::string s = "]";
//   std::cout << isValid(s) << std::endl;
//   return 0;
// }

#include <iostream>

class A {
 public:
  void function1() { std::cout << "hello!" << std::endl; }
};

class B {
 public:
  void function1() { std::cout << "This is function1" << std::endl; }
  void function2() {
    std::cout << "This is function2" << std::endl;
    this->function1();
  }
};

class C : virtual public B
{
  public:
  void function1() { std::cout << "This is function1 in C" << std::endl; }
};

class D : virtual public B
{
  public:
    // void function1() { std::cout << "This is function1 in D" << std::endl; }
};

class E : public C, public D
{
  public:
    // void function3();
};

int main() {
  // A* pA = NULL;
  // pA->function1();

  // B* pB = NULL;
  // pB->function1();
  // pB->function2();

  C* pC = NULL;
  pC->function1();

  // E *pE = NULL;
  // pE->function1();
  return 0;
}