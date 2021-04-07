/*
 * @Descripttion:
 * @version:
 * @Author: Allen Zhuang
 * @Date: 2020-11-19 02:32:28
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-21 14:56:42
 */
#ifndef _SINGLELIST_H
#define _SINGLELIST_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef void* ElementType;

typedef struct singlelistNode {
  ElementType value;
  struct singlelistNode* pNext;
} listNode, *PtrToNode;

typedef struct singlelist {
  PtrToNode pHeader;
  size_t len;
} list, *PtrToList;

PtrToList createList();
void realseList(PtrToList l);
bool isEmpty(PtrToList l);
PtrToList addFirstNode(PtrToList l, ElementType ele);
PtrToList addLastNode(PtrToList l, ElementType ele);
PtrToList insertNode(PtrToList l, PtrToNode oldNode, ElementType ele,
                     bool after);
void delNode(PtrToList l, PtrToNode oldNode);
PtrToNode searchNode(PtrToList l, ElementType key);
PtrToNode searchNodeByIndex(PtrToList l, long index);
PtrToList reserveList(PtrToList l);
size_t listLength(PtrToList l);

#endif  // _SINGLELIST_H