/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-24 20:12:48
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-24 20:51:02
 */
#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

typedef struct arrayQueue {
  int size;    // size of queue
  int num;     // element count of queue
  int head;    // header
  int tail;    // tail
  int* array;  // data array
} stArrayQueue, *PtrArrayQueue;

#define RET_SUCC (0)
#define RET_ERROR (-1)
#define arrayQueue_isEmpty(q) ((q->size) == 0)
#define arrayQueue_isFull(q) ((q->size) == (q->num))

PtrArrayQueue arrayQueue_create(int size);
void arrayQueue_destory(PtrArrayQueue q);
int arrayQueue_enqueue(PtrArrayQueue q, int data);
int arrayQueue_dequeue(PtrArrayQueue q, int* data);

#endif