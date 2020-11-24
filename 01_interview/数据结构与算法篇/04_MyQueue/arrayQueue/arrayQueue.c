/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-24 20:13:34
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-24 20:40:26
 */
#include "arrayQueue.h"

#include <stdlib.h>

PtrArrayQueue arrayQueue_create(int size) {
  PtrArrayQueue q = (PtrArrayQueue)malloc(sizeof(stArrayQueue));
  if (!q) return NULL;
  q->array = (int*)malloc(sizeof(int) * size);
  if (!q->array) {
    free(q);
    return NULL;
  }
  q->size = size;
  q->head = 0;
  q->tail = 0;
  q->num = 0;
  return q;
}

void arrayQueue_destory(PtrArrayQueue q) {
  if (!q) return;
  if (q->array) {
    free(q->array);
  }
  q->size = 0;
  free(q);
  q = NULL;
  return;
}

int arrayQueue_enqueue(PtrArrayQueue q, int data) {
  if (!q) return RET_ERROR;
  if (arrayQueue_isEmpty(q)) return RET_ERROR;

  q->num++;
  q->array[q->tail] = data;
  q->tail = (q->tail + 1) % q->size;
  return RET_SUCC;
}

int arrayQueue_dequeue(PtrArrayQueue q, int* data) {
  if (!q || arrayQueue_isEmpty(q) || !data) return RET_ERROR;
  *data = q->array[q->head];
  --q->num;
  q->head = (q->head + 1) % q->size;
  return RET_SUCC;
}