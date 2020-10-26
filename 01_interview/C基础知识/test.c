/*
 * @Descripttion:
 * @version:
 * @Author: Allen Zhuang
 * @Date: 2020-10-16 04:11:29
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-10-26 16:49:18
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

// #include <ctype.h>
// #include <errno.h>
// #include <limits.h>
// #include <locale.h>
// #include <math.h>
// #include <stdio.h>
// #include <string.h>
// #include <time.h>

// void test_ctype() {
//   int var1 = 'd';
//   int var2 = '2';
//   int var3 = ' ';
//   if (isalnum(var1)) {
//     printf("var1 = |%c|是字母数字\n", var1);
//   }
//   if (isalpha(var1)) {
//     printf("var1 = |%c|是字母\n", var1);
//   }
//   if (isalpha(var2)) {
//     printf("var2 = |%c|是字母\n", var2);
//   } else {
//     printf("var2 = |%c|不是字母\n", var2);
//   }
//   if (isdigit(var1)) {
//     printf("var1 = |%c|是数字\n", var1);
//   } else {
//     printf("var1 = |%c|不是数字\n", var1);
//   }
//   if (isdigit(var2)) {
//     printf("var2 = |%c|是数字\n", var2);
//   } else {
//     printf("var2 = |%c|不是数字\n", var2);
//   }
//   if (isgraph(var3)) {
//     printf("var3 = |%c|是可打印的\n", var3);
//   } else {
//     printf("var3 = |%c|不可打印的\n", var3);
//   }
//   int i = 0;
//   int j = 0;
//   char str1[] = "all \a about \t programming";
//   char str2[] = "shource.ren \n tutorials";
//   while (!iscntrl(str1[i])) {
//     putchar(str1[i]);
//     i++;
//   }
//   while (!iscntrl(str2[j])) {
//     putchar(str2[j]);
//     j++;
//   }
// }

// void test_isprint() {
//   int var1 = 'k';
//   int var2 = ' ';
//   int var3 = '\t';
//   if (isprint(var1)) {
//     printf("var1 = |%c|是可打印的\n", var1);
//   } else {
//     printf("var1 = |%c|是不可打印的\n", var1);
//   }
//   if (isprint(var2)) {
//     printf("var2 = |%c|是可打印的\n", var2);
//   } else {
//     printf("var2 = |%c|是不可打印的\n", var2);
//   }
//   if (isprint(var3)) {
//     printf("var3 = |%c|是可打印的\n", var3);
//   } else {
//     printf("var3 = |%c|是不可打印的\n", var3);
//   }
// }

// void test_ispunct() {
//   int var1 = 't';
//   int var2 = '1';
//   int var3 = '/';
//   int var4 = ' ';
//   if (ispunct(var1)) {
//     printf("var1 = |%c|是标点字符符号\n", var1);
//   } else {
//     printf("var1 = |%c|不是标点字符符号\n", var1);
//   }
//   if (ispunct(var2)) {
//     printf("var2 = |%c|是标点字符符号\n", var2);
//   } else {
//     printf("var2 = |%c|不是标点字符符号\n", var2);
//   }
//   if (ispunct(var3)) {
//     printf("var3 = |%c|是标点字符符号\n", var3);
//   } else {
//     printf("var3 = |%c|不是标点字符符号\n", var3);
//   }
//   if (ispunct(var4)) {
//     printf("var4 = |%c|是标点字符符号\n", var4);
//   } else {
//     printf("var4 = |%c|不是标点字符符号\n", var4);
//   }
// }

// void test_isxdigit() {
//   char str1[] = "titil";
//   char str2[] = "0xee";
//   if (isxdigit(str1[0])) {
//     printf("str1 = |%s|是十六进制数字\n", str1);
//   } else {
//     printf("str1 = |%s|不是十六进制数字\n", str1);
//   }
//   if (isxdigit(str2[0])) {
//     printf("str2 = |%s|是十六进制数字\n", str2);
//   } else {
//     printf("str2 = |%s|不是十六进制数字\n", str2);
//   }
// }

// extern int errno;
// void test_errno() {
//   FILE *fp;
//   fp = fopen("file.txt", "r");
//   if (fp == NULL) {
//     fprintf(stderr, "Value of errno:%d\n", errno);
//     fprintf(stderr, "Error opening file:%s\n", strerror(errno));
//   } else {
//     fclose(fp);
//   }
// }

// void test_EDOM() {
//   double val;
//   errno = 0;
//   val = sqrt(-10);
//   if (errno == EDOM) {
//     printf("InVaild value\n");
//   } else {
//     printf("Vaild value\n");
//   }
//   errno = 0;
//   val = sqrt(10);
//   if (errno == EDOM) {
//     printf("InVaild value\n");
//   } else {
//     printf("Vaild value\n");
//   }
// }

// void test_ERANGE() {
//   double val;
//   double x;
//   x = 1.00000;
//   val = log(x);
//   if (errno == ERANGE) {
//     printf("Log(%f) is out of range\n", x);
//   } else {
//     printf("Log(%f) = %f\n", x, val);
//   }
//   x = 0.00000;
//   val = log(x);
//   if (errno == ERANGE) {
//     printf("Log(%f) is out of range\n", x);
//   } else {
//     printf("Log(%f) = %f\n", x, val);
//   }
// }

// void test_setlocale() {
//   time_t currtime;
//   struct tm *timer;
//   char buffer[80];

//   time(&currtime);
//   timer = localtime(&currtime);

//   printf("Locale is:%s\n", setlocale(LC_ALL, "en_GB"));
//   strftime(buffer, 80, "%c", timer);
//   printf("Date is:%s\n", buffer);
//   printf("Locale is:%s\n", setlocale(LC_ALL, "de_DE"));
//   strftime(buffer, 80, "%c", timer);
//   printf("Date is:%s\n", buffer);
// }

// void test_localeconv() {
//   struct lconv *lc;
//   setlocale(LC_MONETARY, "it_IT");
//   lc = localeconv();
//   printf("Locale Currency Symbol:%s\n", lc->currency_symbol);
//   printf("International Currency Symbol:%s\n", lc->int_curr_symbol);

//   setlocale(LC_MONETARY, "en_US");
//   lc = localeconv();
//   printf("Locale Currency Symbol:%s\n", lc->currency_symbol);
//   printf("International Currency Symbol:%s\n", lc->int_curr_symbol);

//   setlocale(LC_MONETARY, "zh_CN");
//   lc = localeconv();
//   printf("Locale Currency Symbol:%s\n", lc->currency_symbol);
//   printf("International Currency Symbol:%s\n", lc->int_curr_symbol);

//   printf("Decimal Point=%s\n", lc->decimal_point);
// }

// #include <math.h>
// #include <stdio.h>
/* 以下C99
// #define PI 3.14159265
// void test_sin() {
//   double x, ret, val;
//   x = 45.0;
//   val = PI / 180;
//   ret = sin(x * val);
//   printf("%lf 的正弦是 %lf度\n", x, ret);
// }
// void test_asin() {
//   double x, ret, val;
//   x = 0.9;
//   val = 180.0 / PI;
//   ret = asin(x) * val;
//   printf("%lf 的反正弦是 %lf度\n", x, ret);
// }

void test_exp() {
  double x = 1.0;
  printf("e 的 %lf 次幂是 %lf\n", x, exp(x));
  printf("e 的 %lf 次幂是 %lf\n", x + 1, exp(x + 1));
  printf("e 的 %lf 次幂是 %lf\n", x + 2, exp(x + 2));
}
*/

// #include <signal.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// void signalhander(int);

// void test_signal() {
//   signal(SIGINT, signalhander);
//   while (1) {
//     printf("开始休眠1秒钟\n");
//     sleep(5);
//   }
// }

// void signalhander(int signum) {
//   printf("捕获到信号 %d, 跳出...\n", signum);
//   exit(1);
// }

// #include <signal.h>
// #include <stdio.h>

// void signal_catchfunc(int);

// void test_raise() {
//   int ret;
//   ret = signal(SIGINT, signal_catchfunc);
//   if (ret == SIG_ERR) {
//     printf("错误：不能设置信号处理程序\n");
//     exit(0);
//   }
//   printf("开始生成一个信号\n");
//   ret = raise(SIGINT);
//   if (ret != 0) {
//     printf("错误：不能生成SIGINT信号\n");
//     exit(0);
//   }
//   printf("退出...\n");
// }

// void signal_catchfunc(int signal) { printf("！！信号捕获！！\n"); }

// #include <stdarg.h>
// #include <stdio.h>

// int sum(int, ...);

// void test_va_arg() {
//   printf("3+4+5=%d\n", sum(3, 3, 4, 5));
//   printf("9+13+14+5=%d\n", sum(4, 9, 13, 4, 5));
// }

// int sum(int num_args, ...) {
//   int val = 0;
//   int i;
//   va_list ap;
//   va_start(ap, num_args);
//   for (i = 0; i < num_args; ++i) {
//     val += va_arg(ap, int);
//   }
//   va_end(ap);
//   return val;
// }

#include <stddef.h>
#include <stdio.h>

struct address {
  char name[50];
  char street[50];
  int phone;
};

void test_offsetof() {
  printf("address结构中的name偏移为%d\n", offsetof(struct address, name));
  printf("address结构中的street偏移为%d\n", offsetof(struct address, street));
  printf("address结构中的phone偏移为%d\n", offsetof(struct address, phone));
}

void main(void) {
  // test_ctype();
  // test_isprint();
  // test_ispunct();
  // test_isxdigit();
  // test_errno();
  // test_EDOM();
  // test_ERANGE();
  // test_setlocale();
  // test_localeconv();
  // test_sin();
  // test_exp();
  // test_signal();
  // test_raise();
  // test_va_arg();
  test_offsetof();
}
