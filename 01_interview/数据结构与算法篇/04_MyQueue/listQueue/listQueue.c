/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-24 20:21:13
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-28 16:27:10
 */
#include "listQueue.h"

#include <stdlib.h>

PtrToListQueue listQueue_create() {
  PtrToListQueue q = (PtrToListQueue)malloc(sizeof(stListQueue));
  if (!q) return NULL;
  q->num = 0;
  q->head = NULL;
  q->tail = NULL;
  return q;
}

void listQueue_destory(PtrToListQueue q) {
  if (!q) return NULL;
  ElementType data = NULL;
  while (!listQueue_isEmpty(q)) listQueue_dequeue(q, &data);
  free(q);
  q = NULL;
  return;
}

int listQueue_enqueue(PtrToListQueue q, ElementType data) {
  if (!q) return RET_ERROR;
  PtrToListQueueNode node =
      (PtrToListQueueNode)malloc(sizeof(stListQueue_node));
  if (!node) return RET_ERROR;
  node->data = data;
  if (!q->head) {
    q->head = node;
  } else {
    q->tail->next = node;
  }
  q->tail = node;
  ++q->num;
  return RET_SUCC;
}

int listQueue_dequeue(PtrToListQueue q, ElementType* data) {
  if (!q || !data || listQueue_isEmpty(q)) return RET_ERROR;
  PtrToListQueueNode tmpNode = q->head;
  *data = tmpNode->data;
  q->head = q->head->next;
  --q->num;
  if (!q->head) q->tail = NULL;
  free(tmpNode);
  tmpNode = NULL;
  return RET_SUCC;
}