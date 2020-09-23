/*
 * @Descripttion: MyList类
 * @version: V1.00
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-09-21 15:10:21
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-09-23 17:12:07
 *  部分GCC编译器不支持模版类的分离编译
 */


#ifndef MYLIST_H
#define MYLIST_H

#include <stddef.h>
#include <stdlib.h>
using namespace std;
typedef int Rank;                     //秩
#define  ListNodePosi(T)  ListNode<T>* //列表节点位置

template <typename T>
struct ListNode
{
    //成员
    T data; //数据
    ListNodePosi(T) pred; //前驱
    ListNodePosi(T) succ; //后继

    // 构造函数
    ListNode()  {}
    ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL):data(e),pred(p),succ(s) {}

    //操作接口
    ListNodePosi(T) insertAsPred(const T& e);
    ListNodePosi(T) insertAsSucc(const T& e);
};

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


template<typename T>
class myList
{
private:
    int _size;  //规模
    ListNodePosi(T)  header; //头部结点
    ListNodePosi(T)  tailer; //尾部结点

protected:
    void init();
    int  clear();
    void copyNodes(ListNodePosi(T), int);
    void merge(ListNodePosi(T)&, int, myList<T>&, ListNodePosi(T), int);
    void mergeSort(ListNodePosi(T)&, int);
    void selectionSort(ListNodePosi(T), int);
    void insertSort(ListNodePosi(T), int);

public:
    //构造函数
    myList()  { init(); }
    myList(ListNodePosi(T) p, int n);
    myList(const myList<T>& L);
    myList(const myList<T>& L, Rank r, int n);
    //析构函数
    ~myList();
//    //只读访问接口
    int size() const { return _size; }
    bool empty() const { return _size<=0; }
    T& operator[](Rank r) const;
    ListNodePosi(T) first() const { return header->succ; }
    ListNodePosi(T) last() const { return tailer->pred; }
    bool vaild(ListNodePosi(T) p)
    { return p && (header != p) && (tailer != p); }
    int disordered() const;
    ListNodePosi(T) find(const T& e) const  { return find(e, _size, tailer); }
    ListNodePosi(T) find(const T& e, int n, ListNodePosi(T) p) const;
    ListNodePosi(T) search(const T& e) const  { return search(e, _size, tailer); }
    ListNodePosi(T) search(const T& e, int n, ListNodePosi(T) p) const;
    ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);
    ListNodePosi(T) selectMax() { return selectMax(header->succ, _size); }
    //可写访问接口
    ListNodePosi(T) insertAsFirst(const T& e);
    ListNodePosi(T) insertAsLast(const T& e);
    ListNodePosi(T) insertBefore(ListNodePosi(T) p, const T& e);
    ListNodePosi(T) insertAfter(ListNodePosi(T) p, const T& e);
    T remove(ListNodePosi(T) p);
    void merge(myList<T>& L){ merge(first(), _size, L, L.first(), L._size); }
    void sort(ListNodePosi(T) p, int n);
    void sort() { sort(first(), _size); }
    int  deduplicate();
    int  uniquify();
    void reverse();
    //遍历
    void traverse(void (*)(T&)); //遍历,依次实施visit操作(函数指针,只读或局部性修改)
    template<typename VST> //操作器
    void traverse(VST&); //遍历,依次实施visit操作(函数对象,全局性修改)
};

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
        if((cur = cur->succ)->data > max->data){
            max = cur;
        }
    }
    return max;
}

template<typename T>
void myList<T>::merge(ListNodePosi(T)& p, int n, myList<T>& L, ListNodePosi(T) q, int m)
{
    ListNodePosi(T) pp = p->pred;
    while(0 < m){
        if(0 < n && p->data <= q->data){
            if(q == (p = p->succ) ) break;
            n--;
        }else{
            insertBefore( p, L.remove((q = q->succ)->pred) );
            m--;
        }
    }
    p = pp->succ;
}

template<typename T>
void myList<T>::mergeSort(ListNodePosi(T)& p, int n)
{
    if(n < 2) return;
    int m = n >> 2;
    ListNodePosi(T) q = p;
    while(m > 0){
        q = q->succ;
        m--;
    }
    mergeSort(p, m);
    mergeSort(q, n-m);
    merge(p, n, *this, q, n-m);
}

#endif //LISTNODE_H
