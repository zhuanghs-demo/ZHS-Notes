/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-23 17:04:12
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-24 11:10:44
 */
#include "arrayStack.h"

#include <stdlib.h>
#include <string.h>

PtrArrayStack arrayStack_create(int size) {
  PtrArrayStack s = NULL;
  s = (PtrArrayStack)malloc(sizeof(stArrayStack));
  if (!s) {
    return NULL;
  }
  s->size = size;
  s->pos = POS_INIT;
  s->array = (int*)malloc(sizeof(int) * size);
  if (!s->array) {
    free(s);
    s = NULL;
  }
  return s;
}

void arrayStack_destory(PtrArrayStack s) {
  if (!s) return;
  if (s->array) {
    free(s->array);
    s->array = NULL;
  }
  if (s) {
    free(s);
    s = NULL;
  }
  return;
}

int arrayStack_pop(PtrArrayStack s) {
  if (!s) return;
  int data = 0;
  if (arrayStack_isEmpty(s)) {
    return RET_ERROR;
  }
  data = s->array[s->pos];
  --s->pos;
  return data;
}

int arrayStack_push(PtrArrayStack s, int data) {
  if (!s || arrayStack_isFull(s)) {
    return RET_ERROR;
  }
  s->array[++s->pos] = data;
  return RET_SUCC;
}
int arrayStack_push_new(PtrArrayStack s, int data) {
  if (!s) return RET_ERROR;
  if (!arrayStack_isFull(s)) {
    return arrayStack_push(s, data);
  }
  PtrArrayStack sNew = arrayStack_create(2 * (s->size));
  if (!sNew) return RET_ERROR;
  memmove(sNew->array, s->array, sizeof(s->array));
  sNew->array[++s->pos] = data;
  sNew->pos = s->pos;
  sNew->size = 2 * (s->size);
  arrayStack_destory(s);
  return sNew;
}

// void arrayStack_dump(PtrArrayStack s);