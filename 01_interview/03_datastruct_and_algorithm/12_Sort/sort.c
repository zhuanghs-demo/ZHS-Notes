/*
 * @Descripttion:
 * @version:
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-11-28 16:48:07
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2021-04-09 03:43:10
 */
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;

//打印数组
void printArray(int* pArr, int n) {
  int i = 0;
  for (; i < n; ++i) {
    printf("%d\t", *(pArr + i));
  }
  printf("\n");
}

//插入排序
void insertionSort(KeyType k[], int n) {
  int i, j;
  KeyType tmp;
  for (i = 1; i < n; ++i) {
    tmp = k[i];
    j = i - 1;
    while (j >= 0 && tmp < k[j])
      k[j + 1] = k[j--];
    k[j + 1] = tmp;
  }
  return;
}

//选择排序
void selectionsort(KeyType k[], int n) {
  int i, j;
  int min;
  KeyType tmp;
  for (i = 0; i < n; ++i) {
    min = i;
    for (j = i + 1; j < n; ++j) {
      if (k[j] < k[min]) {
        min = j;
      }
    }
    if (min != i) {
      tmp = k[min];
      k[min] = k[i];
      k[i] = tmp;
    }
  }
}

//冒泡排序
void bubblesort(KeyType k[], int n) {
  int i, j, flag = 1;
  KeyType tmp;
  for (i = 0; i < n - 1 && flag == 1; ++i) {
    flag = 0;
    for (j = 0; j < n - i - 1; ++j) {
      if (k[j] > k[j + 1]) {
        tmp = k[j + 1];
        k[j + 1] = k[j];
        k[j] = tmp;
        flag = 1;
      }
    }
  }
}

//希尔排序
void shellsort(KeyType k[], int n) {
  int i, j, flag, gap;
  KeyType tmp;
  gap = n;
  while (gap > 1) {
    gap = gap / 2;
    do {
      flag = 0;
      for (i = 0; i + gap < n; ++i) {
        j = i + gap;
        if (k[j] < k[i]) {
          tmp = k[i];
          k[i] = k[j];
          k[j] = tmp;
          flag = 1;
        }
      }
    } while (flag != 0);
  }
}

void swap(KeyType* a, KeyType* b) {
  KeyType tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

//快速排序
void quicksort(KeyType k[], int s, int t) {
  int i, j;
  if (s < t) {
    i = s;
    j = t + 1;
    while (1) {
      do
        i++;
      while (!(k[s] <= k[i] || i == t));
      do
        j--;
      while (!(k[s] >= k[j] || j == s));
      if (i < j) {
        swap(&k[i], &k[j]);
      } else {
        break;
      }
    }
    swap(&k[s], &k[j]);
    quicksort(k, s, j - 1);
    quicksort(k, j + 1, t);
  }
}

//堆排序
void adjust(KeyType k[], int i, int n) {
  int j;
  KeyType tmp;
  tmp = k[i];
  j = 2 * i;
  while (j <= n) {
    if (j < n && k[j] < k[j + 1]) {
      j++;
    }
    if (tmp >= k[j]) {
      break;
    }
    k[j / 2] = k[j];
    j = 2 * j;
  }
  k[j / 2] = tmp;
}

void heapsort(KeyType k[], int n) {
  int i;
  KeyType tmp;
  for (i = (n - 1) / 2; i >= 0; --i) {
    adjust(k, i, n - 1);
  }

  for (i = n - 1; i > 0; --i) {
    tmp = k[i];
    k[i] = k[0];
    k[0] = tmp;
    adjust(k, 0, i - 1);
  }
}

//归并排序

void main() {
  int a[10] = {2, 5, 6, 3, 7, 8, 0, 9, 12, 1};
  printf("The orginal data array is:\n");
  printArray(a, 10);
  // insertionSort(a, 10);
  // selectionsort(a, 10);
  // bubblesort(a, 10);
  // shellsort(a, 10);
  // quicksort(a, 0, 9);
  heapsort(a, 10);
  printf("The result of sorting for the array is:\n");
  printArray(a, 10);
  return;
}