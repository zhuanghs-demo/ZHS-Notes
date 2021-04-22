/*
 * @Descripttion:
 * @version:
 * @Author: Allen Zhuang
 * @Date: 2021-04-14 20:27:14
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2021-04-15 00:08:23
 */
/*编程基本功*/

// #include <dirent.h> //文件夹
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// 1.字符类型统计器
// 【题目要求】请编写一个C程序，在终端用键盘输入字符串，以 Ctrl +
// Z组合键表示输入完毕，统计输入的字符串中空格符、制表符、换行符的个数，并显示统计的结果。
void demo01_calc_special_char() {
  int space, table, enter = 0;
  char c;
  printf("Please input a string:\n");
  scanf("%c", &c);
  while (c != EOF) {
    switch (c) {
      case 32:
        space++;
        break;
      case 9:
        table++;
        break;
      case 10:
        enter++;
        break;
      default:
        break;
    }
    scanf("%c", &c);
  }
  printf("The number of space:%d\n", space);
  printf("The number of table:%d\n", table);
  printf("The number of enter:%d\n", table);
  getchar();
  return;
}

// 2.计算字符的ASCII码
// 【题目要求】编写一个程序，在终端输入一个字符，输出它的 ASCII码。
void demo02_calc_character_ascii() {
  char c;
  printf("Please input a character:\n");
  scanf("%c", &c);
  getchar();
  printf("The ascii of the character is %d\n", c);
}

// 3.嵌套if-else的妙用
//【题目要求】
// 学校进行成绩分级管理，取消分数制，改为成绩分级评定。具体办法是∶ 小于 60
// 分为E类; 60分至70 分（不含 70 分）为D类;70 分至80分（不含）为 C类;80分至
// 90分（不含）为 B类;90分以上为 A类。设计一个程序，对输入的成绩进行等级划分。
void demo03_if_else_use() {
  int score;
  printf("Please input score:\n");
  scanf("%d", &score);
  if (score < 70)
    if (score < 80)
      if (score < 60)
        printf("E\n");
      else
        printf("D\n");
    else
      printf("C\n");
  else if (score < 90)
    printf("B\n");
  else
    printf("A\n");
  getchar();
  return;
}

// 4.基于switch语句的译码器
//【题目要求】给定一个前缀码表如下∶a:1 b:01 c:001
// 又知有一个0/1字符串为∶"001011101001011001"，编写一个C程序，按照给定的前缀码表为该字符串译码
void demo04_decode(char* str, int n) {
  int i = 0;
  while (i < n) {
    switch (str[i]) {
      case '1':
        printf("a");
        break;
      case '0': {
        i++;
        switch (str[i]) {
          case '1':
            printf("b");
            break;
          case '0': {
            i++;
            switch (str[i]) {
              case '1':
                printf("c");
                break;
              default:
                break;
            }
          } break;
          default:
            break;
        }
      } break;
      default:
        break;
    }
    i++;
  }
}

void demo04_decode_test() {
  char a[] = {"001011101001011001"};
  demo04_decode(a, 18);
}

// 5.判断闰年
// 【题目要求】输入一个年份，判断该年是否是闰年。
void demo05_is_leap_year() {
  int year;
  printf("Please input a year:\n");
  scanf("%d", &year);
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    printf("%d is leap year\n", year);
  } else {
    printf("%d is not leap year\n", year);
  }
}

// 6.指针变量用作参数
//【题目要求】编写一个函数
// inputArray（），该函数被主函数调用，通过该函数实现向主函数中定义的数组输入数据。
void intputArray(int* array, int n) {
  int i;
  for (i = 0; i < n; ++i) {
    scanf("%d", array + i);
  }
}

void demo06_pointer_as_function_para() {
  int array[5], i;
  printf("Please input data for array:\n");
  intputArray(array, 5);
  for (i = 0; i < 5; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// 7.矩阵的转置运算
// 【题目要求】用键盘从终端输入一个3 行
// 4列的矩阵，编写一个函数对该矩阵进行转置操作。
void inuput_matrix(int (*a)[4], int n, int m) {
  int i, j;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      scanf("%d", *(a + i) + j);
    }
  }
}

void output_matrix(int (*b)[3], int n, int m) {
  int i, j;
  for (i = 0; i < m; ++i) {
    for (j = 0; j < n; ++j) {
      printf("%d\t", *(*(b + i) + j));
    }
    printf("\n");
  }
}

void transpose_matrix(int (*a)[4], int (*b)[3]) {
  int i, j;
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 4; ++j) {
      b[j][i] = a[i][j];
    }
  }
}

void demo07_matrix_transpose() {
  int a[3][4] = {0}, b[4][3] = {0};
  printf("Please input the 3*4 matrix data:\n");
  inuput_matrix(a, 3, 4);
  transpose_matrix(a, b);
  printf("The transpose matrix is:\n");
  output_matrix(b, 3, 4);
}

void demo08_bit_swap() {
  int a = 10, b = 5;
  printf("Before swap : a=%d,b=%d\n", a, b);
  a = a ^ b;
  b = b ^ a;
  a = a ^ b;
  printf("After swap : a=%d,b=%d\n", a, b);
}

int bit_abs(int a) {
  int i = a >> 31;
  return ((a ^ i) - i);
}

void demo09_bit_abs() {
  int a = -10;
  printf("abs(a)=%d\n", bit_abs(a));
}

int bit_count(int a) {
  int count = 0;
  while (a) {
    a &= (a - 1);
    count++;
  }
  return count;
}

void demo10_bit_count() {
  int a = 0x000000ab;
  printf("num=%#010x\n", a);
  char s[32];
  itoa(a, s, 2);
  printf("num=%032s\n", s);
  int count = bit_count(a);
  printf("bit_count:%d\n", count);
}

void demo11_file_read_write() {
  char file_name[20];
  char text1[20] = {'\0'}, text2[20] = {'\0'};
  printf("Please input file name path:\n");
  scanf("%s", file_name);
  FILE* fp;
  fp = fopen(file_name, "w");
  const char* p = "Hello world!";
  strcpy(text1, p);
  int file_len = strlen(text1);
  fwrite(text1, file_len, 1, fp);
  printf("The file has been saved\n");
  fclose(fp);
  fp = NULL;
  fp = fopen(file_name, "r");
  if (fp) {
    fread(text2, file_len, 1, fp);
    printf("The content of th file:%s\n", text2);
  }
  fclose(fp);
}

void demo12_size_of_file() {
  FILE* fp = NULL;
  long size;
  fp = fopen("hello1.txt", "r");
  if (fp) {
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    printf("The length of the file is %d bytes\n", size);
  }
  fclose(fp);
}

void demo13_process_runtime() {
  clock_t start, end;
  int i;
  start = clock();
  Sleep(1000);
  end = clock();
  printf("The time was:%fl\n", (end - start) / CLK_TCK);
}

void demo14_decimal_to_bianary() {
  int a = 15;
  int r;
  int i = 0;
  int stack[32] = {0};
  while (a) {
    r = a % 2;
    a /= 2;
    stack[i++] = r;
  }
  for (i -= 1; i >= 0; --i) {
    printf("%d", stack[i]);
  }
  printf("\n");
}

void main(int argc, char* argv[]) {
  //   demo01_calc_special_char();
  // demo02_calc_character_ascii();
  // demo03_if_else_use();
  // demo04_decode_test();
  // demo05_is_leap_year();
  // demo06_pointer_as_function_para();
  // demo07_matrix_transpose();
  // demo08_bit_swap();
  // demo09_bit_abs();
  // demo10_bit_count();
  // demo11_file_read_write();
  // demo12_size_of_file();
  // demo13_process_runtime();
  demo14_decimal_to_bianary();
  return;
}
