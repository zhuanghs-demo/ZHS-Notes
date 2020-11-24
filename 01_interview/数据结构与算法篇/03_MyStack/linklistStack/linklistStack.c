/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-23 16:55:27
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-24 14:39:10
 */
#include "linklistStack.h"

#include <stdlib.h>

PtrLinklistStack stack_create() {
  PtrLinklistStack s = (PtrLinklistStack)malloc(sizeof(stLinklistStack));
  if (!s) return NULL;
  s->next = NULL;
  return s;
}

void stack_destory(PtrLinklistStack s) {
  if (!s) return;
  PtrLinklistStack pTmp = NULL;
  while (s->next) {
    pTmp = s->next;
    s->next = s->next->next;
    free(pTmp);
  }
  free(s);
  s = NULL;
  return;
}

int stack_pop(PtrLinklistStack s, int* data) {
  if (!s || !data) return RET_ERROR;
  if (linklistStack_isEmpty(s)) return RET_ERROR;
  PtrLinklistStack pTop = NULL;
  pTop = s->next;
  s->next = s->next->next;
  *data = pTop->data;
  free(pTop);  // destory node when pop
  return RET_SUCC;
}

int stack_push(PtrLinklistStack s, int data) {
  if (!s) return RET_ERROR;
  PtrLinklistStack pTop = (PtrLinklistStack)malloc(sizeof(stLinklistStack));
  if (!pTop) return RET_ERROR;
  pTop->data = data;
  pTop->next = s->next;
  s->next = pTop;
  return RET_SUCC;
}