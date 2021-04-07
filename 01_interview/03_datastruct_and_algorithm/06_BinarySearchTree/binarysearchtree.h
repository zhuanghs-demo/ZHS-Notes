/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-28 16:32:05
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-30 16:56:09
 */
#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#define RET_SUCC 0
#define RET_NULLPTR -1
#define RET_MALLOC_FAILED -2
#define RET_ERROR -3

#define COMPARE_EQUAL 0
#define COMPARE_GREATER 1
#define COMPARE_LOWER -1

typedef int DataType;
typedef int* UseType;

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
PtrTreeNode bstree_search(PtrTree tree, DataType data);
int bstree_insert(PtrTree tree, DataType data);
int bstree_delete(PtrTree tree, DataType data);
void bstree_destory_node(PtrTree tree, PtrTreeNode root);
void bstree_destory(PtrTree tree);
void bstree_inorder_node(PtrTreeNode tree);
int bstree_compare(DataType key1, DataType key2);
void bstree_dump(PtrTree tree);

#endif