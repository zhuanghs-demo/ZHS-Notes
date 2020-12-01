/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-28 16:34:35
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-12-01 02:40:43
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

int hstable_insert(ptr_hstable h, KeyType key, ValueType value);
ptr_hstable_node hstable_delete(ptr_hstable h, KeyType key);
ValueType hstable_search(ptr_hstable h, KeyType key);