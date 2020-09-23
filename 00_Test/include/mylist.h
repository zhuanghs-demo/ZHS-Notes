/*
 * @Descripttion: MyList类
 * @version: V1.00
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-09-21 15:10:21
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-09-23 14:42:35
 */

#ifndef MYLIST_H
#define MYLIST_H

#include "listnode.h"

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
    myList() { init(); }
    myList(const myList<T>& L);
    myList(const myList<T>& L, Rank r, int n);
    myList(ListNodePosi(T) p, int n);
    //析构函数
    ~myList();
    //只读访问接口
    Rank size() const { return _size; }
    bool empty() const { return _size<=0; }
    T& operator[](Rank r) const;
    ListNodePosi(T) first() const { return header->succ; }
    ListNodePosi(T) last() const { return tailer->pred; }
    bool vaild(ListNodePosi(T) p)
    { return p && (header != p) && (tailer != p); }
    int disordered() const;
    ListNodePosi(T) find(const T& e) const
    { return find(e, _size, tailer); }
    ListNodePosi(T) find(const T& e, int n, ListNodePosi(T) p) const;
    ListNodePosi(T) search(const T& e) const
    { return search(e, _size, tailer); }
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


#endif //LISTNODE_H