/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-24 15:32:50
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2021-02-02 18:58:03
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

#include <stdio.h>

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

class C : virtual public B {
 public:
  void function1() { std::cout << "This is function1 in C" << std::endl; }
};

class D : virtual public B {
 public:
  // void function1() { std::cout << "This is function1 in D" << std::endl; }
};

class E : public C, public D {
 public:
  // void function3();
};

class X {};

class Y : public virtual X {};
class Z : public virtual X {};
class P : public Y, public Z {};
void test_demo() {
  double dValue = -40.0;
  unsigned int pbyValue = dValue;
  printf("dwValue:%f, nValue:%u, sizeof(int):%d\n", dValue, pbyValue,
         sizeof(unsigned int));

  unsigned int pbyValue2 = 4294967281;
  float fValue2 = dValue;
  printf("dwValue:%f, nValue:%f, sizeof(float):%d, sizeof(double):%d\n", dValue,
         fValue2, sizeof(float), sizeof(double));

  double dValue3 = -40.0;
  unsigned long pbyValue3 = dValue3;
  printf("dwValue:%f, nValue:%f\n", dValue3, pbyValue3);
}

int main() {
  // A* pA = NULL;
  // pA->function1();

  // B* pB = NULL;
  // pB->function1();
  // pB->function2();

  // C* pC = NULL;
  // pC->function1();

  // E *pE = NULL;
  // pE->function1();

  std::cout << "X:" << sizeof(X) << '\n'
            << "Y:" << sizeof(Y) << '\n'
            << "Z:" << sizeof(Z) << '\n'
            << "P:" << sizeof(P) << '\n';

  test_demo();
  return 0;
}