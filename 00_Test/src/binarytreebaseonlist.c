/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-27 15:36:34
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-28 16:00:53
 */
#include "binarytreebaseonlist.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listQueue.h"

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