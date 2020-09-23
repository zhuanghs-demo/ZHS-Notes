/*
 * @Descripttion:  listnode.cpp
 * @version: V1.00
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-09-23 14:43:45
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-09-23 15:39:18
 */
#include "../include/listnode.h"

//前插入
template<typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(const T& e)
{
    ListNodePosi(T) x = new ListNode(e,pred,this);
    pred->succ = x; pred = x;
    return x;
}

//后插入
template<typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(const T& e)
{
    ListNodePosi(T) x = new ListNode(e,this,succ);
    succ->pred = x; succ = x;
    return x;
}

