/*
 * @Descripttion:
 * @version:
 * @Author: Allen Zhuang
 * @Date: 2020-11-19 02:32:42
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-19 21:14:50
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
  PtrToNode preNode = NULL;
  PtrToNode curNode = l->pHeader->pNext;
  while (curNode) {
    preNode = curNode;
    curNode = curNode->pNext;
    preNode->pNext = NULL;
    free(preNode);
    preNode = NULL;
  }
  l->pHeader->pNext = NULL;
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

PtrToList insertNode(PtrToList l,
                     PtrToNode oldNode,
                     ElementType ele,
                     bool after) {
  if (!l || !oldNode)
    return l;
  PtrToNode node = malloc(sizeof(listNode));
  if (!node)
    return l;
  node->value = ele;
  if (after) {
    node->pNext = oldNode->pNext;
    oldNode->pNext = node;
  } else {
    PtrToNode preNode = l->pHeader;
    while (preNode->pNext != oldNode) {
      preNode = preNode->pNext;
    }
    if (preNode) {
      preNode->pNext = node;
      node->pNext = oldNode;
    }
  }
  ++l->len;
  return l;
}

void delNode(PtrToList l, PtrToNode oldNode) {
  if (!l || !oldNode)
    return l;
  PtrToNode preNode = l->pHeader;
  while (preNode->pNext != oldNode && preNode->pNext) {
    preNode = preNode->pNext;
  }
  if (!preNode->pNext)
    return;
  preNode->pNext = oldNode->pNext;
  oldNode->pNext = NULL;
  free(oldNode);
  oldNode = NULL;
  --l->len;
  return;
}
PtrToNode searchNode(PtrToList l, ElementType key);
PtrToNode searchNodeByIndex(PtrToList l, long index);
PtrToList reserveList(PtrToList l);
size_t listLength(PtrToList l) {
  if (!l)
    return 0;
  return l->len;
}