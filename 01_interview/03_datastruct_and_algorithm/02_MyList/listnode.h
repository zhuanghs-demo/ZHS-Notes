/*
 * @Descripttion: ListNode
 * @version: V1.00
 * @@Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-09-21 11:13:25
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-09-21 18:54:47
 */

#include <stddef.h>
using namespace std;
typedef int Rank;                     //秩
#define ListNodePosi(T) ListNode<T> * //列表节点位置

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

