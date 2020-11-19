/*
 * @Descripttion:
 * @version:
 * @Author: Allen Zhuang
 * @Date: 2020-11-19 02:32:42
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-19 16:40:53
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
    pTmpNode = NULL;
  }
  free(l->pHeader);
  l->pHeader = NULL;
  l->len = 0;
  return;
}

bool isEmpty(PtrToList l) {
  assert(!l);
  return l->pHeader->pNext == NULL;
}

PtrToList addFirstNode(PtrToList l, ElementType ele) {
  if (!l) {
    return l;
  }
  PtrToNode node = malloc(sizeof(listNode));
  if (!node) {
    return l;
  }
  node->value = ele;
  node->pNext = l->pHeader->pNext;
  l->pHeader->pNext = node;
  ++l->len;
  return l;
}

PtrToList addLastNode(PtrToList l, ElementType ele) {
  if (!l) {
    return l;
  }
  PtrToNode node = malloc(sizeof(listNode));
  if (!node) {
    return l;
  }
  node->value = ele;
  node->pNext = NULL;
  if (l->len == 0 && !l->pHeader->pNext) {
    l->pHeader->pNext = node;
  } else {
    PtrToNode preNode = l->pHeader;
    PtrToNode tailnode = l->pHeader->pNext;
    while (tailnode) {
      preNode = tailnode;
      tailnode = tailnode->pNext;
    }
    preNode->pNext = node;
  }
  ++l->len;
  return l;
}

PtrToList insertNode(PtrToList l, PtrToNode oldNode, ElementType ele,
                     bool after) {
  if (!l || !oldNode) return l;
}