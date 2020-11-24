/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-23 16:55:12
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-24 14:21:20
 */

#ifndef LINK_LIST_STACK_H
#define LINK_LIST_STACK_H
typedef struct linklistStack {
  int data;
  struct linklistStack* next;
} stLinklistStack, *PtrLinklistStack;

#define linklistStack_isEmpty(lstStack) (lstStack->next == NULL)
#define RET_ERROR (-1)
#define RET_SUCC (0)

PtrLinklistStack stack_create();
void stack_destory(PtrLinklistStack s);
int stack_pop(PtrLinklistStack s, int* data);
int stack_push(PtrLinklistStack s, int data);

#endif