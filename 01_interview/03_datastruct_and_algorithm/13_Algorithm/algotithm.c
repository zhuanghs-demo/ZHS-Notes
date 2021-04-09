#include <stdio.h>
#include <stdlib.h>

// 1.穷举法
// eg:输出1-100之间的素数
int isPrime(int n) {
  int i;
  for (i = 2; i < n; ++i) {
    if (n % i == 0) return 0;
  }
  return 1;
}

void getPrime(int low, int high) {
  int i;
  for (i = low; i <= high; ++i) {
    if (isPrime(i)) {
      printf("%d\t", i);
    }
  }
  printf("\n");
}

void getPrime_test() {
  printf("The whole primes between 1 and 100 are:\n");
  getPrime(1, 100);
}

// eg:借书问题：TOM有5本新书，要借给A、B、C三位同学，每人只能借一本，问有多少种借书方案
void borrowBooks() {
  printf(
      "There are different methods for TOM to distribute his books to "
      "A/B/C:\n");
  int i, j, k, count = 0;
  for (i = 1; i <= 5; ++i) {
    for (j = 1; j <= 5; ++j) {
      for (k = 1; k <= 5; ++k) {
        if (i != j && i != k && j != k) {
          printf("<%d,%d,%d>\t", i, j, k);
          count++;
        }
      }
    }
  }
  printf("\ncount:%d\n", count);
}

// 2.分治与递归算法
// eg:计算整数的划分数 n=n1+n2+...+nk (n1>=n2>=...>=nk>=1,k>=1) 最大加数m
int partition_of_integer(int n, int m) {
  if (n == 1 || m == 1) return 1;
  if (m > n) return partition_of_integer(n, n);
  if (m == n) return partition_of_integer(n, m - 1) + 1;
  return partition_of_integer(n, m - 1) + partition_of_integer(n - m, m);
}

void partition_of_integer_test() {
  int i, counts;
  for (i = 1; i <= 10; ++i) {
    counts = partition_of_integer(i, i);
    printf("The number of divsion of %d is %d\n", i, counts);
  }
}

//递归的折半查找算法
int bin_search(int k[], int n, int key) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (key == k[mid]) {
      return mid;
    }
    if (key > k[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

void bin_search_test() {
  int k[] = {1, 2, 3, 5, 6, 7, 12, 14, 15, 24, 25, 37};
  int n = 24, pos;
  pos = bin_search(k, 12, n);
  printf("%d is at the %dth unit in the array\n", n, pos);
}

// 3.贪心算法
// eg:最优装船问题：有一批集装箱要装入一个载重量为
// C的货船中，每个集装箱的质量由用户自己输入指定，在货船的装载体积不限的前提下，如何装载集装箱才能尽可能多地将集装箱装入货船中?
void sort_container(int w[], int t[], int n) {}

void loading_ship(int x[], int w[], int c, int n) {}

void main(int argc, char* argv[]) {
  //   getPrime_test();
  //   borrowBooks();
  //   partition_of_integer_test();
  bin_search_test();
  return;
}
