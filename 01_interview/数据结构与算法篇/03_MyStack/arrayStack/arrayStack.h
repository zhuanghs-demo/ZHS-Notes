/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-23 17:03:58
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-24 10:33:56
 */
#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

typedef struct _array_stack {
  int size;
  int pos;
  int* array;
} stArrayStack, *PtrArrayStack;

#define RET_ERROR (-1)
#define RET_SUCC (0)
#define POS_INIT (-1)
#define arrayStack_size(stArrayStack) (stArrayStack->size)
#define arrayStack_isEmpty(stArrayStack) (stArrayStack->pos == POS_INIT)
#define arrayStack_isFull(stArrayStack) \
  (stArrayStack->pos == (stArrayStack->size - 1))

PtrArrayStack arrayStack_create(int size);
void arrayStack_destory(PtrArrayStack s);
int arrayStack_pop(PtrArrayStack s);
int arrayStack_push(PtrArrayStack s, int data);
int arrayStack_push_new(PtrArrayStack s, int data);
void arrayStack_dump(PtrArrayStack s);

#endif  // ARRAY_STACK_H
