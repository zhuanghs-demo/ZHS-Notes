/*
 * @Descripttion: 
 * @version: 
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-09-21 15:15:55
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-09-22 05:22:06
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
        if(e == (p = p->pred)->data) 
        return p;
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

template<typename T>
T myList<T>::remove(ListNodePosi(T) p)
{
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;
    --_size;
    return e;
}

template<typename T>
myList<T>::~myList()
{
    clear();
    delete header;
    delete tailer;
}

template<typename T>
int myList<T>::clear()
{
    int oldSize = _size;
    while(0 < _size){
        remove(header->succ);
    }
    return oldSize;
}

template<typename T>
int myList<T>::deduplicate()
{
    if(_size < 2){
        return 0;
    }
    int oldSize = _size;
    ListNodePosi(T) p = header;
    Rank r = 0;
    while( tailer != (p = p->succ)){
        ListNodePosi(T) q = find(p->data, r, p);
        q ? remove(p) : r++;
    }
    return oldSize - _size;
}

template<typename T>
void myList<T>::traverse(void (*visit)(T&))
{
    for(ListNodePosi(T) p = header->succ; p != tailer; p = p->succ){
        visit(p->data);
    }
}

template<typename T>
template<typename VST>
void myList<T>::traverse(VST& visit)
{
    for(ListNodePosi(T) p = header->succ; p != tailer; p = p->succ){
        visit(p->data);
    }
}

template<typename T>
int myList<T>::uniquify()
{
    if(_size < 2){
        return 0;
    }
    int oldSize = _size;
    ListNodePosi(T) p;
    ListNodePosi(T) q;
    for(p = header, q = p->succ; tailer != q; p = q, q = q->succ){
        if(p->data = q->data){
            remove(q);
            q = p;
        }
    }
    return oldSize - _size;
}

template<typename T>
ListNodePosi(T) myList<T>::search(const T& e, int n, ListNodePosi(T) p) const
{
    while (0 < n--){
       if( ((p = p->pred)->data) <= e)
       break;
    }
    return p;
}

template<typename T>
void myList<T>::sort(ListNodePosi(T) p, int n)
{
    switch (rand() % 3)
    {
    case 1:
        insertSort(p, n);
        break;
    case 2:
        selectionSort(p, n);
        break;
    default:
        mergrSort(p, n);
        break;
    }
}

template<typename T>
void myList<T>::insertSort(ListNodePosi(T) p, int n)
{
    for(Rank r = 0; r < n; r++){
        insertAfter(search(p->data, r, p), p->data);
        p = p->succ;
        remove(p->pred);
    }
}

template<typename T>
void myList<T>::selectionSort(ListNodePosi(T) p, int n)
{
    ListNodePosi(T) head = p->pred;
    ListNodePosi(T) tail = p;
    for(Rank r = 0; r < n; r++){
        tail = tail->succ;
    }
    while(0 < n){
        ListNodePosi(T) max = selectMax(head->succ, n);
        insertBefore(tail, remove(max));
        tail = tail->pred;
        n--;
    }
}

template<typename T>
ListNodePosi(T) myList<T>::selectMax(ListNodePosi(T) p, int n)
{
    ListNodePosi(T) max = p;
    for(ListNodePosi(T) cur = p; 1 < n; n--){
        if(!lt((cur = cur->succ)->data, max->data)){
            max = cur;
        }
    }
    return max;
}

