/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-28 16:34:10
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-12-01 02:27:02
 */
#ifndef _LISTHASH_H_
#define _LISTHASH_H_

typedef void* KeyType;
typedef void* ValueType;
#define HSTABLE_MAX_NODES (0xffffffff)

typedef struct _hstable_node {
  KeyType key;
  ValueType value;
  struct _hstable_node* next;
} hstable_node, *ptr_hstable_node;

typedef struct _hstable {
  ptr_hstable_node* hstables; /*哈希桶*/
  int size;                   /*哈希桶的最大数量*/
  int nel;                    /*哈希桶中元素的个数*/
  int (*hash_value)(struct _hstable* h, const KeyType key); /*哈希函数*/
  int (*keycmp)(struct _hstable* h,
                const KeyType key1,
                const KeyType key2); /*哈希key比较函数，当哈希数值一致时使用*/
  void (*hash_node_free)(hstable_node* node);
} hstable, *ptr_hstable;

typedef int (*hash_value_func)(struct _hstable* h, const KeyType key);
typedef int (*keycmp_func)(struct _hstable* h,
                           const KeyType key1,
                           const KeyType key2);
typedef void (*hash_node_free_func)(hstable_node* node);

/*根据当前结构体元素的地址，获取到结构体首地址*/
#define offsetof(TYPE, MEMBER) (size_t & ((TYPE*)0)->MEMBER)
#define container(ptr, type, member)                  \
  ({                                                  \
    const typeof(((type*)0)->member)* __mptr = (ptr); \
    \ 
    (type*)((char*)__mptr - offsetof(type, member));  \
  })

ptr_hstable hstable_create(int size,
                           hash_value_func hash_value,
                           keycmp_func keycmp,
                           hash_node_free_func hash_node_free);
void hstable_destory(ptr_hstable h);
int hstable_insert(ptr_hstable h, KeyType key, ValueType value);
ptr_hstable_node hstable_delete(ptr_hstable h, KeyType key);
ValueType hstable_search(ptr_hstable h, KeyType key);

#endif