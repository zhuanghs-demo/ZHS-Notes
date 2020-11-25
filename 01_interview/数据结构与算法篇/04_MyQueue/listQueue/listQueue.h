/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-24 20:20:50
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-25 09:40:02
 */
#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

typedef struct listQueue_node {
  int data;
  struct listQueue_node* next;
} stListQueue_node, *PtrToListQueueNode;

typedef struct listQueue {
  int num;
  PtrToListQueueNode head;
  PtrToListQueueNode tail;
} stListQueue, *PtrToListQueue;

#define RET_SUCC (0)
#define RET_ERROR (-1)
#define listQueue_isEmpty(q) ((q->num) == 0)

PtrToListQueue listQueue_create();
void listQueue_destory(PtrToListQueue q);
int listQueue_enqueue(PtrToListQueue q, int data);
int listQueue_dequeue(PtrToListQueue q, int* data);

#endif