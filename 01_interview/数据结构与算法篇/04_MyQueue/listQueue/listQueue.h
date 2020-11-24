/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-24 20:20:50
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-24 20:50:38
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
} stListQueue, PtrToListQueue;

#define RET_SUCC (0)
#define RET_ERROR (-1)
#define listQueue_isEmpty(q) ((q->num) == 0)

#endif