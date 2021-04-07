/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-27 15:36:34
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-28 14:29:00
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listQueue.h"

typedef struct _treeNode {
  int data;
  struct _treeNode* lChild;
  struct _treeNode* rChild;
} TNode, stTree, *PtrTree;

void binarytree_create(PtrTree* root) {
  int a = 0;
  printf(
      "\r\nPlease input node counts(if the input count is 100, current node "
      "create completed):");
  scanf("%d", &a);
  if (a == 100) {
    *root = NULL;
  } else {
    *root = (PtrTree)malloc(sizeof(stTree));
    if (*root == NULL) return;
    (*root)->data = a;
    printf("\r\nCreate %d lChild:", a);
    binarytree_create(&((*root)->lChild));
    printf("\r\nCreate %d rChild:", a);
    binarytree_create(&((*root)->rChild));
  }
  return;
}

void binarytree_destory(PtrTree root) {
  if (!root) return;
  binarytree_destory(root->lChild);
  binarytree_destory(root->rChild);
  free(root);
  root = NULL;
}

/*先序遍历:根结点--》左子树---》右子树*/
void binarytree_preorder(PtrTree root) {
  if (!root) return;
  printf(" %d ", root->data);
  binarytree_preorder(root->lChild);
  binarytree_preorder(root->rChild);
  return;
}

/*中序遍历:左子树--》跟节点---》右子树*/
void binarytree_inorder(PtrTree root) {
  if (!root) return;
  binarytree_inorder(root->lChild);
  printf(" %d ", root->data);
  binarytree_inorder(root->rChild);
  return;
}

/*后序遍历:左子树---》右子树-》根节点*/
void binarytree_postorder(PtrTree root) {
  if (!root) return;
  binarytree_postorder(root->lChild);
  binarytree_postorder(root->rChild);
  printf(" %d ", root->data);
  return;
}

/*层次遍历*/
void binarytree_levelorder(PtrTree root) {
  if (!root) return;
  TNode* node = NULL;
  PtrToListQueue queue = NULL;
  queue = listQueue_create();
  listQueue_enqueue(queue, (ElementType)root);
  while (!listQueue_isEmpty(queue)) {
    listQueue_dequeue(queue, (ElementType)&node);
    printf(" %d ", node->data);
    if (node->lChild) listQueue_enqueue(queue, (ElementType)node->lChild);
    if (node->rChild) listQueue_enqueue(queue, (ElementType)node->rChild);
  }
  if (node) free(node);
  listQueue_destory(queue);
  return;
}

/*打印叶子节点*/
void binarytree_printfleaf(PtrTree root) {
  if (!root) return;
  if (!root->lChild && !root->rChild) {
    printf(" %d ", root->data);
  } else {
    binarytree_printfleaf(root->lChild);
    binarytree_printfleaf(root->rChild);
  }
  return;
}

/*打印叶子的个数*/
int binarytree_getleafnum(PtrTree root) {
  if (!root) return 0;
  if (!root->lChild && !root->rChild) {
    return 1;
  }
  return binarytree_getleafnum(root->lChild) +
         binarytree_getleafnum(root->rChild);
}

int binarytree_getheight(PtrTree root) {
  if (!root) return 0;
  int lheight = 0;
  int rheight = 0;
  lheight = binarytree_getheight(root->lChild);
  rheight = binarytree_getheight(root->rChild);
  return lheight > rheight ? (lheight + 1) : (rheight + 1);
}

int main() {
  PtrTree root = NULL;
  setenv("MALLOC_TRACE", "1.txt", 1);
  mtrace();

  printf("\r\n创建二叉树:");
  binarytree_create(&root);
  printf("\r\n先序遍历二叉树:");
  binarytree_preorder(root);
  printf("\r\n中序遍历二叉树:");
  binarytree_inorder(root);
  printf("\r\n后序遍历二叉树:");
  binarytree_postorder(root);
  printf("\r\n层次遍历二叉树:");
  binarytree_levelorder(root);

  printf("\r\n打印二叉树叶子节点:");
  binarytree_printfleaf(root);
  printf("\r\n打印二叉树叶子节点个数:%d", binarytree_getleafnum(root));
  printf("\r\n打印二叉树高度:%d", binarytree_gethigh(root));

  binarytree_destory(root);

  muntrace();
  return 0;
}