/*
 * @Descripttion: 
 * @version: 
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-09-25 16:37:07
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-09-28 23:13:07
 */
#ifndef BINTREE_H
#define BINTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
    BinNodePosi(T) insertAsLC(const T&);//作为左节点插入
    BinNodePosi(T) insertAsRC(const T&);//作为右节点插入
    BinNodePosi(T) succ();//取直接后继
    template<typename VST> void travLevel(VST&);//子树层次遍历
    template<typename VST> void travPre(VST&);//子树先序遍历
    template<typename VST> void travIn(VST&);//子树中序遍历
    template<typename VST> void travPost(VST&);//子树后序遍历
    //比较器、判等器
    bool operator<(const BinNode& bn) { return this->data <  bn.data; }
    bool operator==(const BinNode& bn) { return this->data == bn.data; } 
};


//BinNode状态和性质的判断
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lChild))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rChild))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lChild)
#define HasRChild(x) ((x).rChild)
#define HasChild(x) (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!HasChild(x))

//与BinNode有特定关系的节点或指针
#define sibing(p) (IsLChild(*(p)) ? (p)->parent->lChild : (p)->parent->rChild) //兄弟
#define uncle(p) (IsLChild(*((p)->parent)) ? (p)->parent->parent->lChild : (p)->parent->parent->rChild) //叔叔
#define FormParentTo(x) (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lChild : (x).parent->rChild))//来自父亲的指针


template<typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(const T& e){ return lChild = new BinNode(e, this); }

template<typename T>
BinNodePosi(T) BinNode<T>::insertAsRC(const T& e){ return rChild = new BinNode(e, this); }

template<typename T> 
template<typename VST>
void BinNode<T>::travIn(VST& visit)
{
    switch (rand() % 5){
        case 1:
            travIn_I1(this, visit);
            break;
        case 2:
            travIn_I2(this, visit);
            break;
        case 3:
            travIn_I3(this, visit);
            break;
        case 4:
            travIn_I4(this, visit);
            break;
        default:
            travIn_R(this, visit);
            break;
    }
}


template<typename T>
class BinTree
{
protected:
    int _size;
    BinNodePosi(T) _root;
    virtual int updateHeight(BinNodePosi(T) x);
    void updateHeightAbove(BinNodePosi(T) x);
public:
    BinTree():_size(0),_root(NULL) {}
    ~BinTree() { if(_size > 0) remove(_root); }
    int size() const { return _size; }
    bool empty() const { return !_root; }
    BinNodePosi(T) root() const { return _root; }
    BinNodePosi(T) insertAsRoot(const T& e);
    BinNodePosi(T) insertAsLC(BinNodePosi(T) x, const T& e);
    BinNodePosi(T) insertAsRC(BinNodePosi(T) x, const T& e);
    BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>* &T);
    BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>* &T);
    int remove(BinNodePosi(T) x);
    BinTree<int>* secede(BinNodePosi(T) x);
    template<typename VST>
    void travLevel(VST& visit){ if(_root) _root->travLevel(visit); }
    template<typename VST>
    void travPre(VST& visit){ if(_root) _root->travPre(visit); }
    template<typename VST>
    void travIn(VST& visit){ if(_root) _root->travIn(visit); }
    template<typename VST>
    void travPost(VST& visit){ if(_root) _root->travPost(visit); }
    bool operator<(const BinTree<T>& t)
    { return _root && t._root && _root < t._root); }
    bool operator==(const BinTree<T>& t)
    { return _root && t._root && (_root == t._root); }
};

template<typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x)
{
    return x->height = 1 + stature(x->lChild)>stature(x->rChild) ? stature(x->lChild): stature(x->rChild);
}

template<typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x)
{
    while (x){
        updateHeight(x);
        x = x->parent;
    }
}





#endif //BINTREE_H