/*
 * @Descripttion: main.cpp
 * @version: V1.00
 * @Author: Allen Zhuang
 * @Date: 2020-09-22 19:56:05
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-28 14:47:23
 */
// #include <stdio.h>
// #include <stack>
// #include <string>
// #include <vector>
// #include "include/mylist.h"
// #include "include/print.h"

// //八皇后
// struct Queen  //皇后类
// {
//   int _x;
//   int _y;

//   Queen(int x, int y) : _x(x), _y(y) {}

//   bool operator==(const Queen& q) const {
//     return (_x == q._x) || (_y == q._y) || (_x + _y == q._x + q._y) ||
//            (_x - _y == q._x - q._y);
//   }

//   bool operator!=(const Queen& q) const { return !(*this == q); }
// };

// int find(stack<Queen> s, const Queen& q) {
//   int n = 0;
//   int nSize = s.size();
//   while (nSize-- > 0) {
//     if (q == s.top()) {
//       n++;
//     }
//     s.pop();
//   }
//   return n;
// }

// void placeQueen(int N) {
//   stack<Queen> solu;
//   Queen q(0, 0);
//   int nCheck = 0;
//   int nSolu = 0;
//   do {
//     if (q._y >= N || solu.size() >= N) {
//       q = solu.top();
//       solu.pop();
//       q._y++;
//     }
//     while (q._y < N && (find(solu, q) > 0)) {
//       q._y++;
//       nCheck++;
//     }
//     if (q._y < N) {
//       solu.push(q);
//       if (solu.size() >= N) {
//         nSolu++;
//       }
//       q._x++;
//       q._y = 0;
//     }

//   } while (q._x > 0 || q._y < N);
//   printf("nCheck=%d\nnSolu=%d\n", nCheck, nSolu);
// }

// int main(int argv, char** argc) {
//   // printMsg();
//   // myList<int> L;
//   // L.insertAsFirst(1);
//   // L.insertAsLast(2);
//   // printf("L.size()=%d\n", L.size());
//   // stack<Queen> sk;
//   // sk.push(Queen(0,0));
//   // sk.push(Queen(0,1));
//   // Queen q(0, 0);
//   // printf("n=%d\n",find(sk, q));
//   placeQueen(8);
//   return 0;
// }
#ifdef __cplusplus
extern "C" {
#endif

// #include <stdio.h>

// #include "include/singlelist.h"

// void printfList(PtrToList list) {
//   printf("Header");
//   PtrToNode curNode = list->pHeader;
//   while (curNode->pNext) {
//     curNode = curNode->pNext;
//     void* ele = curNode->value;
//     printf("->%d", ele);
//   }
//   printf("\n");
//   return;
// }

// void printfNode(PtrToNode node) {
//   if (!node) return;
//   printf("%d\n", node->value);
//   return;
// }

// int main(void) {
//   PtrToList list = createList();
//   addFirstNode(list, (void*)1);
//   addFirstNode(list, (void*)2);
//   addLastNode(list, (void*)3);
//   addLastNode(list, (void*)5);
//   printf("before length=%d\n", listLength(list));
//   printfList(list);
//   PtrToNode tmpNode = searchNode(list, (void*)3);
//   if (tmpNode) delNode(list, tmpNode);
//   printf("after length=%d\n", listLength(list));
//   printfList(list);
//   PtrToNode curNode = searchNodeByIndex(list, 0);
//   printfNode(curNode);
//   curNode = searchNodeByIndex(list, 2);
//   printfNode(curNode);
//   reserveList(list);
//   printfList(list);
//   //  curNode = searchNodeByIndex(list, 7);
//   realseList(list);
//   return 0;
// }

#ifdef __cplusplus
}
#endif