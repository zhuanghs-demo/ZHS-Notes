/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-28 14:34:33
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-28 14:38:58
 */

typedef struct _treeNode {
  int data;
  struct _treeNode* lChild;
  struct _treeNode* rChild;
} TNode, stTree, *PtrTree;

void binarytree_create(PtrTree* root);
void binarytree_destory(PtrTree root);
void binarytree_preorder(PtrTree root);
void binarytree_inorder(PtrTree root);
void binarytree_postorder(PtrTree root);
void binarytree_levelorder(PtrTree root);
void binarytree_printfleaf(PtrTree root);
int binarytree_getleafnum(PtrTree root);
int binarytree_getheight(PtrTree root);
