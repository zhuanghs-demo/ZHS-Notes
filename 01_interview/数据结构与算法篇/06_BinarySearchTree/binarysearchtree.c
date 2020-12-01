/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-28 16:32:25
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-12-01 00:47:24
 */
#include "binarysearchtree.h"

#include <assert.h>
#include <stdlib.h>

PtrTree bstree_create(compare_func compare, destory_func destory) {
  PtrTree tree = NULL;
  tree = (PtrTree)malloc(sizeof(bstree));
  if (!tree)
    return NULL;
  tree->root = NULL;
  tree->size = 0;
  tree->compare = compare;
  tree->destory = destory;
  return tree;
}

PtrTreeNode bstree_search(PtrTree tree, DataType data) {
  if (!tree || bstree_is_empty(tree))
    return NULL;
  PtrTreeNode node = NULL;
  int res = 0;
  node = tree->root;
  while (node) {
    res = tree->compare(data, node->data);
    if (res == 0) {
      return node;
    } else if (res > 0) {
      node = node->rChild;
    } else {
      node = node->lChild;
    }
  }
  return NULL;
}

int bstree_insert(PtrTree tree, DataType data) {
  if (!tree)
    return RET_NULLPTR;
  PtrTreeNode tmp = NULL;
  PtrTreeNode node = NULL;
  int res = 0;
  node = (PtrTreeNode)malloc(sizeof(bstree_node));
  if (!node)
    return RET_MALLOC_FAILED;
  node->data = data;
  node->lChild = NULL;
  node->rChild = NULL;
  if (bstree_is_empty(tree)) {
    tree->root = node;
    ++tree->size;
    return RET_SUCC;
  }
  tmp = tree->root;
  while (tmp) {
    res = tree->compare(data, tmp->data);
    if (res > 0) {
      if (!tmp->rChild) {
        tmp->rChild = node;
        ++tree->size;
        return RET_SUCC;
      }
      tmp = tmp->rChild;
    } else {
      if (!tmp->lChild) {
        tmp->lChild = node;
        ++tree->size;
        return RET_SUCC;
      }
      tmp = tmp->lChild;
    }
  }
  return RET_ERROR;
}

int bstree_delete(PtrTree tree, DataType data) {
  if (!tree || bstree_is_empty(tree))
    return RET_ERROR;
  PtrTreeNode node = NULL;
  PtrTreeNode pnode = NULL;
  PtrTreeNode minnode = NULL;
  PtrTreeNode pminnode = NULL;
  int res = 0;
  node = tree->root;
  /*1、如果要删除node有2个子节点，需要找到右子树的最小节点minnode，
   * 更新minnode和node节点数据，这样minnode节点就是要删除的节点
   * 再更新node和pnode节点指向要删除的节点*/
  while (node && ((res = tree->compare(data, node->data)) != 0)) {
    pnode = node;
    if (res > 0)
      node = node->rChild;
    else
      node = node->lChild;
  }
  if (!node)
    return RET_NULLPTR;
  if (node->lChild && node->rChild) {
    minnode = node->rChild;
    pminnode = node;
    while (minnode) {
      pminnode = minnode;
      minnode = minnode->lChild;
    }
    /*node 节点和minnode节点数据互换*/
    DataType tmp;
    tmp = node->data;
    node->data = minnode->data;
    minnode->data = tmp;
    /*更新要删除的节点和其父节点*/
    node = minnode;
    pnode = pminnode;
  }
  /*2、当前要删除的节点只有左孩子或者右孩子时，直接父节点指向删除的节点的子节点*/
  if (node->lChild != NULL) {
    minnode = node->lChild;
  } else if (node->rChild != NULL) {
    minnode = node->rChild;
  } else {
    minnode = NULL;
  }
  if (!pnode) {
    tree->root = minnode;
  } else if (pnode->lChild == node) {
    pnode->lChild = minnode;
  } else {
    pnode->rChild = minnode;
  }
  --tree->size;
  free(node);
  return RET_SUCC;
}

void bstree_destory_node(PtrTree tree, PtrTreeNode root) {
  assert(tree);
  if (!root)
    return;
  bstree_destory_node(tree, root->lChild);
  bstree_destory_node(tree, root->rChild);
  free(root);
  return;
}

void bstree_destory(PtrTree tree) {
  assert(tree);
  bstree_destory_node(tree, tree->root);
  free(tree);
  return;
}

void bstree_inorder_node(PtrTreeNode root) {
  if (!root)
    return;
  bstree_inorder_node(root->lChild);
  printf(" %d ", root->data);
  bstree_inorder_node(root->rChild);
  return;
}

int bstree_compare(DataType key1, DataType key2) {
  if (key1 == key2) {
    return COMPARE_EQUAL;
  } else if (key1 > key2) {
    return COMPARE_GREATER;
  } else {
    return COMPARE_LOWER;
  }
}

void bstree_dump(PtrTree tree) {
  if (!tree || bstree_is_empty(tree)) {
    printf("\r\n 当前树是空树");
  }
  printf("\r\nSTART-----------------%d------------\r\n", tree->size);
  bstree_inorder_node(tree->root);
  printf("\r\nEND---------------------------------", tree->size);
}
