/*
 * @Descripttion: 
 * @version: 
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-09-21 15:15:55
 * @LastEditors: Allen zhuang
 * @LastEditTime: 2020-09-21 17:52:55
 */
#include "mylist.h"

template<typename T> 
void myList<T>::init()
{
    header = new ListNode<T>;
    tailer = new ListNode<T>;
    header->pred = NULL;
    header->succ = tailer;
    tailer->pred = header;
    tailer->succ = NULL;
    _size = 0;
}

template<typename T>
void myList<T>::copyNodes(ListNodePosi(T) p, int n)
{
    init();
    while(n--){
        insertAsLast(p->data);
        p = p->succ;
    }
}

template<typename T>
myList<T>::myList(const myList<T>& L)
{
    copyNodes(L.first(), L._size);
}

template<typename T>
myList<T>::myList(const myList<T>& L, Rank r, int n)
{
    copyNodes(L[r], n);
}

template<typename T>
myList<T>::myList(ListNodePosi(T) p, int n)
{
    copyNodes(p, n);
}


template<typename T>
T& myList<T>::operator[](Rank r) const
{
    ListNodePosi(T) p = first();
    while (0 < r--){
        p = p->succ;
    }
    return p->data;
}

template<typename T>
ListNodePosi(T) myList<T>::find(const T& e, int n, ListNodePosi(T) p) const
{
    while (0 < n--){
        if(e == (p = p->pred)->data) return p;
    }
    return NULL;
}

template<typename T>
ListNodePosi(T) myList<T>::insertAsFirst(const T& e)
{
    ++_size;
    return header->insertAsSucc(e);
}

template<typename T>
ListNodePosi(T) myList<T>::insertAsLast(const T& e)
{
    ++_size;
    return tailer->insertAsPred(e);
}

template<typename T>
ListNodePosi(T) myList<T>::insertBefore(ListNodePosi(T) p,const T& e)
{
    ++_size;
    return p->insertAsPred(e);
}

template<typename T>
ListNodePosi(T) myList<T>::insertAfter(ListNodePosi(T) p,const T& e)
{
    ++_size;
    return p->insertAsSucc(e);
}