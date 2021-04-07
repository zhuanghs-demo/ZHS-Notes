/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-28 16:34:35
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-12-02 01:05:32
 */
#include "listhash.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef MEMORY_TEST
#include <mcheck.h>
#endif

ptr_hstable hstable_create(int size,
                           hash_value_func hash_value,
                           keycmp_func keycmp,
                           hash_node_free_func hash_node_free) {
  ptr_hstable h = NULL;
  int i = 0;
  if ((size < 0) || !hash_value || !keycmp) {
    return NULL;
  }
  h = (ptr_hstable)malloc(sizeof(hstable));
  if (!h)
    return NULL;
  h->hstables = (ptr_hstable_node*)malloc(size * sizeof(ptr_hstable_node));
  if (!h->hstables)
    return NULL;
  h->size = size;
  h->nel = 0;
  h->hash_value = hash_value;
  h->keycmp = keycmp;
  h->hash_node_free = hash_node_free;
  for (; i < size; ++i) {
    h->hstables[i] = NULL;
  }
  return h;
}

void hstable_destory(ptr_hstable h) {
  if (!h)
    return;
  int i = 0;
  ptr_hstable_node cur = NULL;
  ptr_hstable_node tmp = NULL;
  for (; i < h->size; ++i) {
    cur = h->hstables[i];
    while (cur) {
      tmp = cur;
      cur = cur->next;
      h->hash_node_free(tmp);
    }
    h->hstables[i] = NULL;
  }
  free(h->hstables);
  free(h);
  return;
}

int hstable_insert(ptr_hstable h, KeyType key, ValueType value) {
  unsigned int hvalue = 0;
  ptr_hstable_node cur = NULL;
  ptr_hstable_node prev = NULL;
  ptr_hstable_node newnode = NULL;
  if (!h || !key || !value)
    return RET_NULLPTR;
  /*获取hash 数值*/
  hvalue = h->hash_value(h, key);
  cur = h->hstables[hvalue];
  /*hash桶中元素是从小到大排列的，找到要插入的位置*/
  while (cur && (h->keycmp(h, key, cur->key) > 0)) {
    prev = cur;
    cur = cur->next;
  }
  /*如果key和当前key比对一致，直接返回，数据已经存在*/
  if (cur && (h->keycmp(h, key, cur->key) == 0)) {
    return RET_EXISTED;
  }
  newnode = (ptr_hstable_node)malloc(sizeof(hstable_node));
  if (!newnode)
    return RET_OVERFLOW;
  newnode->key = key;
  newnode->value = value;
  if (!prev) {
    newnode->next = h->hstables[hvalue];
    h->hstables[hvalue] = newnode;
  } else {
    newnode->next = prev->next;
    prev->next = newnode;
  }
  h->nel++;
  return RET_SUCCESS;
}

ptr_hstable_node hstable_delete(ptr_hstable h, KeyType key) {
  int hvalue = 0;
  ptr_hstable_node cur = NULL;
  ptr_hstable_node prev = NULL;
  if (!h || !key)
    return NULL;
  /*获取hash 数值*/
  hvalue = h->hash_value(h, key);
  cur = h->hstables[hvalue];
  while (cur && (h->keycmp(h, key, cur->key) >= 0)) {
    if (h->keycmp(h, key, cur->key) == 0) {
      if (!prev) {
        h->hstables[hvalue] = cur->next;
      } else {
        prev->next = cur->next;
      }
      return cur;
    }
    prev = cur;
    cur = cur->next;
  }
  return NULL;
}

ValueType hstable_search(ptr_hstable h, KeyType key) {
  int hvalue = 0;
  ptr_hstable_node cur = NULL;
  if (!h || !key)
    return NULL;
  /*获取hash 数值*/
  hvalue = h->hash_value(h, key);
  cur = h->hstables[hvalue];
  while (cur && (h->keycmp(h, key, cur->key) >= 0)) {
    if (h->keycmp(h, key, cur->key) == 0)
      return cur->value;
    cur = cur->next;
  }
  return NULL;
}

void hstable_dump(ptr_hstable h) {
  ptr_hstable_node cur = NULL;
  int i = 0;
  if (!h)
    return;

  printf("\r\n----开始--size[%d],nel[%d]------------", h->size, h->nel);
  for (i = 0; i < h->size; i++) {
    printf("\r\n hstables[%d]:", i);
    cur = h->hstables[i];
    while ((cur != NULL)) {
      printf("key[%s],value[%s] ", cur->key, cur->value);
      cur = cur->next;
    }
  }
  printf("\r\n----结束--size[%d],nel[%d]------------", h->size, h->nel);
  return;
}

unsigned int simple_hash(const char* str) {
  register unsigned int hash = 0;
  register unsigned int seed = 131;
  while (*str) {
    hash = hash * seed + *str++;
  }
  return hash & (0x7FFFFFFF);
}

int hstable_hvalue(ptr_hstable h, const KeyType key) {
  return (simple_hash(key) % h->size);
}

int hstable_keycmp(ptr_hstable h, const KeyType key1, const KeyType key2) {
  return strcmp(key1, key2);
}

void hstable_node_free(ptr_hstable_node node) {
  struct test_node* ptmp = NULL;
  ptmp = container(node->key, struct test_node, key);
  free(ptmp);
  free(node);
  return;
}

int test_listhash_main() {
  int i = 0;
  int res = 0;
  char* pres = NULL;
  ptr_hstable_node node = NULL;
  struct test_node* p = NULL;
  ptr_hstable h = NULL;

#ifdef MEMORY_TEST
  setenv("MALLOC_TRACE", "1.txt", 1);
  mtrace();
#endif

  h = hstable_create(5, hstable_hvalue, hstable_keycmp, hstable_node_free);
  assert(h != NULL);
  while (1) {
    p = (struct test_node*)malloc(sizeof(struct test_node));
    assert(p != NULL);
    printf("\r\n 请输入key 和value，当可以等于\"quit\"时退出");
    scanf("%s", p->key);
    scanf("%s", p->value);

    if (strcmp(p->key, "quit") == 0) {
      free(p);
      break;
    }

    res = hstable_insert(h, p->key, p->value);
    if (res != 0) {
      free(p);
      printf("\r\n key[%s],value[%s] insert failed %d", p->key, p->value, res);
    } else {
      printf("\r\n key[%s],value[%s] insert success %d", p->key, p->value, res);
    }
  }

  hstable_dump(h);

  while (1) {
    p = (struct test_node*)malloc(sizeof(struct test_node));
    assert(p != NULL);
    printf("\r\n 请输入key 查询value的数值，当可以等于\"quit\"时退出");
    scanf("%s", p->key);

    if (strcmp(p->key, "quit") == 0) {
      free(p);
      break;
    }
    pres = hstable_search(h, p->key);
    if (pres == NULL) {
      printf("\r\n key[%s] search value failed", p->key);
    } else {
      printf("\r\n key[%s],search value[%s] success", p->key, pres);
    }
    free(p);
  }
  hstable_dump(h);

  while (1) {
    p = (struct test_node*)malloc(sizeof(struct test_node));
    assert(p != NULL);
    printf("\r\n 请输入key 删除节点的数值，当可以等于\"quit\"时退出");
    scanf("%s", p->key);

    if (strcmp(p->key, "quit") == 0) {
      free(p);
      break;
    }
    node = hstable_delete(h, p->key);
    if (node == NULL) {
      printf("\r\n key[%s] delete node failed ", p->key);
    } else {
      printf("\r\n key[%s],delete value[%s] success", node->key, node->value);
      h->hash_node_free(node);
    }
    free(p);
    hstable_dump(h);
  }

  hstable_destory(h);
#ifdef MEMORY_TEST
  muntrace();
#endif
  return 0;
}