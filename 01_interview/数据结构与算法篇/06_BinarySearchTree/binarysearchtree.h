/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-28 16:32:05
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-28 17:23:02
 */
#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

typedef void* DataType;

typedef struct _bstree_node {
  DataType data;
  struct _bstree_node* lChild;
  struct _bstree_node* rChild;
} bstree_node, *PtrTreeNode;

typedef struct _bstree {
  int size;
  int (*compare)(DataType key1, DataType key2);
  int (*destory)(DataType data);
  PtrTreeNode root;
} bstree, *PtrTree;

#define bstree_is_empty(bst) (bst->size == 0)
typedef int (*compare_func)(DataType key1, DataType key2);
typedef int (*destory_func)(DataType data);

PtrTree bstree_create(compare_func compare, destory_func destory);

#endif