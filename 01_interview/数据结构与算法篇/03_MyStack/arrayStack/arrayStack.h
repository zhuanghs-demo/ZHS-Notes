/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-23 17:03:58
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-23 17:10:27
 */
#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

typedef struct _array_stack {
  int size;
  int pos;
  int* data;
} stArrayStack;

#define arrayStack_size(stArrayStack) (stArrayStack->size)
#define arrayStack_isEmpty(stArrayStack) (stArrayStack->pos == -1)
#define arrayStack_isFull(stArrayStack) \
  (stArrayStack->pos == (stArrayStack->size - 1))

  

#endif  // ARRAY_STACK_H
