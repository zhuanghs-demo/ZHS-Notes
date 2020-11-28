/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-28 14:47:47
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-28 14:47:48
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binarytreebaseonlist.h"

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
  printf("\r\n打印二叉树高度:%d", binarytree_getheight(root));

  binarytree_destory(root);

  muntrace();
  return 0;
}