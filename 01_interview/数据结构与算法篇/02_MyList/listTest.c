/*
 * @Descripttion:
 * @version:
 * @Author: Allen Zhuang
 * @Date: 2020-11-19 21:26:18
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-19 21:39:12
 */

#include <stdio.h>
#include "singlelist.h"

void printfList(PtrToList list) {
  PtrToNode curNode = list->pHeader;
  while (curNode->pNext) {
    curNode = curNode->pNext;
    void* ele = curNode->value;
    printf("%d-", (int*)ele);
  }
  return;
}

void main(void) {
  PtrToList list = createList();
  addFirstNode(list, (void*)1);
  addFirstNode(list, (void*)2);
  addLastNode(list, (void*)3);
  printfList(list);
  realseList(list);
  return;
}