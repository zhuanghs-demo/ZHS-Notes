/*
 * @Descripttion:
 * @version:
 * @Author: Allen Zhuang
 * @Date: 2020-11-19 02:32:42
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-19 03:52:17
 */

#include "singlelist.h"
PtrToList createList() {
  PtrToList pList = NULL;
  pList = malloc(sizeof(list));
  if (!pList) {
    return NULL;
  }
  pList->pHeader = malloc(sizeof(listNode));
  if (!pList->pHeader) {
    return NULL;
  }
  pList->pHeader->value = NULL;
  pList->pHeader->pNext = NULL;
  pList->len = 0;
  return pList;
}

void realseList(PtrToList l) {
  if (!l) {
    return;
  }
  while (l->pHeader->pNext) {
    PtrToNode pTmpNode = l->pHeader->pNext;
    l->pHeader->pNext = l->pHeader->pNext->pNext;
    if (pTmpNode->value) {
      free(pTmpNode->value);
      pTmpNode->value = NULL;
    }
    pTmpNode->pNext = NULL;
    free(pTmpNode);
  }
  free(l->pHeader);
  l->len = 0;
  return;
}

bool isEmpty(PtrToList l) {
  if (!l) {
    return true;
  }
  return l->pHeader->pNext == NULL;
}