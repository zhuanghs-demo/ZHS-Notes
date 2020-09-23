/*
 * @Descripttion: main.cpp
 * @version: V1.00
 * @Author: Allen Zhuang
 * @Date: 2020-09-22 19:56:05
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-09-23 20:15:05
 */
#include <stdio.h>
#include "include/print.h"
#include "include/mylist.h"

int main(int argv, char** argc)
{
    printMsg();
    myList<int> L;
    L.insertAsFirst(1);
    L.insertAsLast(2);
    printf("L.size()=%d\n", L.size());
    return 0;
}