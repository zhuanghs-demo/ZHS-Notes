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
#include <stdio.h>
#include <stdlib.h>

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
void demo07_matrix_transpose() {}

void main(int argc, char* argv[]) {
  //   demo01_calc_special_char();
  // demo02_calc_character_ascii();
  // demo03_if_else_use();
  // demo04_decode_test();
  // demo05_is_leap_year();
  demo06_pointer_as_function_para();
  return;
}
