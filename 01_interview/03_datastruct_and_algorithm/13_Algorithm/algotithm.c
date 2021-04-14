#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
void sort_container(int w[], int t[], int n) {
  int i, j, tmp;
  int* w_tmp = (int*)malloc(sizeof(int) * n);
  for (i = 0; i < n; ++i) {
    t[i] = i;
  }
  for (i = 0; i < n; ++i) {
    w_tmp[i] = w[i];
  }

  for (i = 0; i < n - 1; ++i) {
    for (j = 0; j < n - i - 1; ++j) {
      if (w_tmp[j] > w_tmp[j + 1]) {
        tmp = w_tmp[j];
        w_tmp[j] = w_tmp[j + 1];
        w_tmp[j + 1] = tmp;
        tmp = t[j];
        t[j] = t[j + 1];
        t[j + 1] = tmp;
      }
    }
  }
}

void loading_ship(int x[], int w[], int c, int n) {
  int i;
  int* t = (int*)malloc(sizeof(int) * n);
  sort_container(w, t, n);
  for (i = 0; i < n; ++i) {
    x[i] = 0;
  }
  for (i = 0; i < n && w[t[i]] <= c; ++i) {
    x[t[i]] = 1;
    c = c - w[t[i]];
  }
}

void loading_ship_test() {
  int c = 15;
  int x[] = {0};
  int w[] = {5, 7, 6, 3, 2};
  int i;
  loading_ship(x, w, c, 5);
  for (i = 0; i < 5; ++i) {
    if (x[i] == 1) printf("BOX:%d\t", i);
  }
  printf("\n");
}

// 4.回溯法
// eg:N皇后问题
int isCorrect(int i, int j, int** Q, int n) {
  int row, col;
  for (row = i, col = 0; col < n; ++col)  //行
    if (Q[row][col] == 1 && col != j) return 0;
  for (col = j, row = 0; row < n; ++row)  //列
    if (Q[row][col] == 1 && row != i) return 0;
  for (row = i - 1, col = j - 1; row >= 0 && col >= 0; --row, --col)  // 左上方
    if (Q[row][col] == 1) return 0;
  for (row = i + 1, col = j - 1; row < n && col >= 0; ++row, --col)  // 左下方
    if (Q[row][col] == 1) return 0;
  for (row = i - 1, col = j + 1; row >= 0 && col < n; --row, ++col)  // 右上方
    if (Q[row][col] == 1) return 0;
  for (row = i + 1, col = j + 1; row < n && col < n; ++row, ++col)  // 右下方
    if (Q[row][col] == 1) return 0;
  return 1;
}
void Queen(int j, int** Q, int n, int* count) {
  int i, k;
  if (j == n) {
    printf("=================slove================\n");
    for (i = 0; i < n; ++i) {
      for (k = 0; k < n; ++k) {
        printf("%d\t", Q[i][k]);
      }
      printf("\n");
    }
    printf("=================end==================\n");
    printf("\n");
    (*count)++;
    return;
  }
  for (i = 0; i < n; ++i) {
    if (isCorrect(i, j, Q, n)) {
      Q[i][j] = 1;
      Queen(j + 1, Q, n, count);
      Q[i][j] = 0;
    }
  }
}

void Queen_place_test() {
  int i;
  int n = 8, cnt = 0;
  int* Q[n];
  for (i = 0; i < n; ++i) {
    int* p = (int*)malloc(sizeof(int) * n);
    memset(p, 0, sizeof(int) * n);
    Q[i] = p;
  }
  Queen(0, Q, n, &cnt);
  printf("count=%d\n", cnt);
}

// 5.数值概率算法
// eg:计算定积分
double Darts(int n) {
  int i, count = 0;
  double x, y;
  time_t t;
  srand((unsigned)time(&t));
  for (i = 0; i < n; ++i) {
    x = rand() % 100 / 100.0;
    y = rand() % 100 / 100.0;
    if (y <= 1 - pow(x, 2)) count++;
  }
  return (double)count / (double)n;
}

void Darts_test() {
  int n = 100000;
  double y = Darts(n);
  printf("y=%lf", y);
}

void main(int argc, char* argv[]) {
  //   getPrime_test();
  //   borrowBooks();
  //   partition_of_integer_test();
  //   bin_search_test();
  //   loading_ship_test();
  // Queen_place_test();
  Darts_test();
  return;
}
