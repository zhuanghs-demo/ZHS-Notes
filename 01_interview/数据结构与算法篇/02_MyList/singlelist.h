/*
 * @Descripttion:
 * @version:
 * @Author: Allen Zhuang
 * @Date: 2020-11-19 02:32:28
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-19 16:37:16
 */
#ifndef _SINGLELIST_H
#define _SINGLELIST_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#define ElementType void*

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

#endif  // _SINGLELIST_H