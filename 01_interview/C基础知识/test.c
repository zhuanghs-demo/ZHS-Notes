/*
 * @Descripttion:
 * @version:
 * @Author: Allen Zhuang
 * @Date: 2020-10-16 04:11:29
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-10-21 19:12:39
 */

// #include <assert.h>
// #include <stdio.h>

// void main(void){
//     int a;
//     char str[50];

//     printf("请输入一个整数值： ");
//     scanf("%d\n", &a);
//     assert(a >= 10);
//     printf("输入的整数是： %d\n", a);

//     printf("请输入字符串： ");
//     scanf("%s\n", &str);
//     assert(str != NULL);
//     printf("输入的字符串是： %s\n", str);
// }

#include <ctype.h>
#include <string.h>

void test_ctype() {
  int var1 = 'd';
  int var2 = '2';
  int var3 = ' ';
  if (isalnum(var1)) {
    printf("var1 = |%c|是字母数字\n", var1);
  }
  if (isalpha(var1)) {
    printf("var1 = |%c|是字母\n", var1);
  }
  if (isalpha(var2)) {
    printf("var2 = |%c|是字母\n", var2);
  } else {
    printf("var2 = |%c|不是字母\n", var2);
  }
  if (isdigit(var1)) {
    printf("var1 = |%c|是数字\n", var1);
  } else {
    printf("var1 = |%c|不是数字\n", var1);
  }
  if (isdigit(var2)) {
    printf("var2 = |%c|是数字\n", var2);
  } else {
    printf("var2 = |%c|不是数字\n", var2);
  }
  if (isgraph(var3)) {
    printf("var3 = |%c|是可打印的\n", var3);
  } else {
    printf("var3 = |%c|不可打印的\n", var3);
  }
  int i = 0;
  int j = 0;
  char str1[] = "all \a about \t programming";
  char str2[] = "shource.ren \n tutorials";
  while (!iscntrl(str1[i])) {
    putchar(str1[i]);
    i++;
  }
  while (!iscntrl(str2[j])) {
    putchar(str2[j]);
    j++;
  }
}

void test_isprint() {
  int var1 = 'k';
  int var2 = ' ';
  int var3 = '\t';
  if (isprint(var1)) {
    printf("var1 = |%c|是可打印的\n", var1);
  } else {
    printf("var1 = |%c|是不可打印的\n", var1);
  }
  if (isprint(var2)) {
    printf("var2 = |%c|是可打印的\n", var2);
  } else {
    printf("var2 = |%c|是不可打印的\n", var2);
  }
  if (isprint(var3)) {
    printf("var3 = |%c|是可打印的\n", var3);
  } else {
    printf("var3 = |%c|是不可打印的\n", var3);
  }
}

void test_ispunct() {
  int var1 = 't';
  int var2 = '1';
  int var3 = '/';
  int var4 = ' ';
  if (ispunct(var1)) {
    printf("var1 = |%c|是标点字符符号\n", var1);
  } else {
    printf("var1 = |%c|不是标点字符符号\n", var1);
  }
  if (ispunct(var2)) {
    printf("var2 = |%c|是标点字符符号\n", var2);
  } else {
    printf("var2 = |%c|不是标点字符符号\n", var2);
  }
  if (ispunct(var3)) {
    printf("var3 = |%c|是标点字符符号\n", var3);
  } else {
    printf("var3 = |%c|不是标点字符符号\n", var3);
  }
  if (ispunct(var4)) {
    printf("var4 = |%c|是标点字符符号\n", var4);
  } else {
    printf("var4 = |%c|不是标点字符符号\n", var4);
  }
}

void test_isxdigit() {
  char str1[] = "titil";
  char str2[] = "0xee";
  if (isxdigit(str1[0])) {
    printf("str1 = |%s|是十六进制数字\n", str1);
  } else {
    printf("str1 = |%s|不是十六进制数字\n", str1);
  }
  if (isxdigit(str2[0])) {
    printf("str2 = |%s|是十六进制数字\n", str2);
  } else {
    printf("str2 = |%s|不是十六进制数字\n", str2);
  }
}

void main(void) {
  // test_ctype();
  // test_isprint();
  // test_ispunct();
  test_isxdigit();
}
