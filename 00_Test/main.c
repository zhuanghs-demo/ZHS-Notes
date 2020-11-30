/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-28 14:47:47
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-30 17:11:31
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binarysearchtree.h"

// int main() {
//   PtrTree root = NULL;
//   setenv("MALLOC_TRACE", "1.txt", 1);
//   mtrace();

//   printf("\r\n创建二叉树:");
//   binarytree_create(&root);
//   printf("\r\n先序遍历二叉树:");
//   binarytree_preorder(root);
//   printf("\r\n中序遍历二叉树:");
//   binarytree_inorder(root);
//   printf("\r\n后序遍历二叉树:");
//   binarytree_postorder(root);
//   printf("\r\n层次遍历二叉树:");
//   binarytree_levelorder(root);

//   printf("\r\n打印二叉树叶子节点:");
//   binarytree_printfleaf(root);
//   printf("\r\n打印二叉树叶子节点个数:%d", binarytree_getleafnum(root));
//   printf("\r\n打印二叉树高度:%d", binarytree_getheight(root));

//   binarytree_destory(root);

//   muntrace();
//   return 0;
// }

int main() {
  bstree *tree = NULL;
  bstree_node *node = NULL;
  int data = 0;
  int res = 0;

  setenv("MALLOC_TRACE", "1.txt", 1);
  mtrace();

  tree = bstree_create(bstree_compare, NULL);
  assert(tree != NULL);

  while (1) {
    printf("\r\n插入一个数字，输入100时退出：");
    scanf("%d", &data);
    if (data == 100) break;
    res = bstree_insert(tree, data);
    printf("\r\n %d 插入%s成功", data, (res != 0) ? ("不") : (" "));
  }
  bstree_dump(tree);

  while (1) {
    printf("\r\n查询一个数字，输入100时退出：");
    scanf("%d", &data);
    if (data == 100) break;
    node = bstree_search(tree, data);
    printf("\r\n %d %s存在树中", data, (node == NULL) ? ("不") : (" "));
  }
  bstree_dump(tree);
  while (1) {
    printf("\r\n删除一个数字，输入100时退出：");
    scanf("%d", &data);
    if (data == 100) break;
    res = bstree_delete(tree, data);
    printf("\r\n %d 删除%s成功", data, (res != 0) ? ("不") : (" "));
    bstree_dump(tree);
  }

  bstree_destory(tree);

  muntrace();

  return 0;
}
