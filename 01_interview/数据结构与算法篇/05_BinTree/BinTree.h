/*
 * @Descripttion: 
 * @version: 
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-09-25 16:37:07
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-09-25 17:23:13
 */
#ifndef BINTREE_H
#define BINTREE_H

#include <stdlib.h>

#define BinNodePosi(T) BinNode<T>*      //节点位置
#define stature(p)  ((p)? (p)->height: -1)  //树节点高度（空树为-1）
typedef enum {RB_RED, RB_BLACK} RBcolor; //颜色

template<typename T>
struct BinNode  //树节点结构体
{
    //成员
    T data;//数据
    BinNodePosi(T) parent;//父节点
    BinNodePosi(T) lChild;//左节点
    BinNodePosi(T) rChild;//右节点
    int height;//高度
    int npl;//左式堆
    RBcolor color;//颜色
    //构造函数
    BinNode():parent(NULL),lChild(NULL),rChild(NULL),height(0),npl(1),color(RB_RED) {}
    BinNode(T e, BinNodePosi(T) p=NULL, BinNodePosi(T) lc=NULL, BinNodePosi(T) rc=NULL,
                    int h = 0, int np = 1, RBcolor c = RB_RED):data(e), parent(p), lChild(lc), rChild(rc), height(h), npl(np), color(c) {}
    
    //操作接口
    int size();//统计当前节点后代总数，即以其为根节点的子树的规模
    BinNodePosi(T) insertAslc(const T&);//作为左节点插入
    BinNodePosi(T) insertAsrc(const T&);//作为右节点插入
    BinNodePosi(T) succ();//取直接后继
    template<typename VST> void travLevel(VST&);//子树层次遍历
    template<typename VST> void travPre(VST&);//子树先序遍历
    template<typename VST> void travIn(VST&);//子树中序遍历
    template<typename VST> void travPost(VST&);//子树后序遍历
    //比较器、判等器
    bool operator<(const BinNode& bn) { return this->data <  bn.data; }
    bool operator==(const BinNode& bn) { return this->data == bn.data; } 
};









#endif //BINTREE_H