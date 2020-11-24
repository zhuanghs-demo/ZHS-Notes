/*
 * @Descripttion:
 * @version:
 * @Author: Allen Zhuang
 * @Date: 2020-10-16 04:11:29
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-11-24 11:08:07
 * @LastEditTime: 2020-10-31 17:06:56
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

// #include <stddef.h>
// #include <errno.h>
// #include <stdarg.h>
// #include <stdio.h>
// #include <string.h>

// struct address {
//   char name[50];
//   char street[50];
//   int phone;
// };

// void test_offsetof() {
//   printf("address结构中的name偏移为%d\n", offsetof(struct address, name));
//   printf("address结构中的street偏移为%d\n", offsetof(struct address,
//   street)); printf("address结构中的phone偏移为%d\n", offsetof(struct address,
//   phone));
// }

// void test_clearerr() {
//   FILE* fp;
//   int c;

//   fp = fopen("test.txt", "w");
//   c = fgetc(fp);
//   if (ferror(fp)) {
//     printf("读取文件test.txt发生错误1\n");
//   }
//   clearerr(fp);
//   if (ferror(fp)) {
//     printf("读取文件test.txt发生错误2\n");
//   }
//   fclose(fp);
// }

// void test_feof() {
//   FILE* fp;
//   int c;
//   char str[] = "This is a test file!";

//   fp = fopen("test.txt", "w+");
//   if (fp == NULL) {
//     printf("open test.txt failed!\n");
//     return;
//   }
//   fwrite(str, 1, strlen(str), fp);
//   fclose(fp);

//   fp = fopen("test.txt", "r");
//   while (1) {
//     c = fgetc(fp);
//     if (feof(fp)) {
//       break;
//     }
//     fputc(c, stdout);
//   }
//   fclose(fp);
//   return;
// }

// void test_fflush() {
//   char buff[1024];
//   memset(buff, '\0', sizeof(buff));

//   fprintf(stdout, "start IOFBE\n");
//   setvbuf(stdout, buff, _IOFBF, 1024);
//   fprintf(stdout, "This is a test case!\n");
//   fprintf(stdout, "save stdout string to buff\n");
//   fflush(stdout);

//   fprintf(stdout, "It will appear after flush buffer\n");
//   fprintf(stdout, "last sleep 5 seconds\n");
//   sleep(5);
//   return;
// }

// void test_fgetpos() {
//   FILE* fp;
//   fpos_t pos;

//   fp = fopen("file.txt", "w+");
//   if (!ferror(fp)) {
//     fgetpos(fp, &pos);
//     fputs("This is a test file", fp);

//     fsetpos(fp, &pos);
//     fputs("Replace previous text", fp);
//   }
//   fclose(fp);
//   return;
// }

// void test_fread_fwrite() {
//   FILE* fp;
//   char c[] = "This is a test file";
//   char buff[1024];

//   fp = fopen("file.txt", "w+");
//   if (!ferror(fp)) {
//     fwrite(c, strlen(c), 1, fp);

//     fseek(fp, SEEK_SET, 0);
//     fread(buff, strlen(c), 1, fp);
//     fprintf(stdout, buff);
//   fp = fopen("file.txt", "r+");
//   if (fp == NULL) return;
//   fwrite(c, strlen(c), 1, fp);
//   fseek(fp, SEEK_SET, 0);
//   fread(buff, strlen(c), 1, fp);
//   fprintf(stdout, buff);
//   fclose(fp);
//   return;
// }

// void test_fseek() {
//   FILE* fp;
//   fp = fopen("file1.txt", "w+");
//   fputs("This is a test file!", fp);
//   fseek(fp, 8, SEEK_SET);
//   fputs("C Programming language!", fp);
//   fclose(fp);
//   return;
// }

// extern int errno;
// void test_ftell() {
//   FILE* fp;
//   long int len;
//   fp = fopen("file2.txt", "r");
//   if (fp == NULL) {
//     fprintf(stderr, "invalue:%d\n", errno);
//     fprintf(stderr, "error desc:%s\n", strerror(errno));
//   } else {
//     fseek(fp, 0, SEEK_END);
//     len = ftell(fp);
//     fprintf(stdout, "file length is:%ld\n", len);
//     fclose(fp);
//   }
//   return;
// }

// void test_printfile(const char* filename) {
//   FILE* fp;
//   int c;

//   fp = fopen(filename, "r");
//   if (fp == NULL) return;
//   while (1) {
//     c = fgetc(fp);
//     if (feof(fp)) {
//       break;
//     }
//     printf("%c", c);
//   }
//   printf("\n");
//   return;
// }

// void test_remove() {
//   FILE* fp;
//   char filename[] = "file2.txt";
//   int ret;

//   fp = fopen(filename, "w");
//   fprintf(fp, "This is also a test file");
//   fclose(fp);
//   test_printfile(filename);
//   ret = remove(filename);
//   if (ret) {
//     fprintf(stdout, "Remove the file failed");
//   } else {
//     fprintf(stdout, "Remove the file success");
//   }
//   return;
// }

// void test_rename() {
//   char oldName[] = "file1.txt";
//   char newName[] = "newFile1.txt";
//   int ret;

//   ret = rename(oldName, newName);
//   if (ret) {
//     fprintf(stdout, "Rename the file failed");
//   } else {
//     fprintf(stdout, "Rename the file success");
//   }
//   return;
// }

// void test_rewind() {
//   FILE* fp;
//   int ch;

//   fp = fopen("newFile.txt", "r");
//   if (fp == NULL) return;
//   while (1) {
//     ch = fgetc(fp);
//     if (feof(fp)) {
//       break;
//     }
//     printf("%c", ch);
//   }
//   printf("\n");
//   rewind(fp);
//   while (1) {
//     ch = fgetc(fp);
//     if (feof(fp)) {
//       break;
//     }
//     printf("%c", ch);
//   }
//   fclose(fp);
//   return;
// }
// void test_setbuf() {
//   char buf[BUFSIZ];

//   setbuf(stdout, buf);
//   puts("Set stdout to buf");
//   sleep(5);
//   fflush(stdout);
//   return;
// }

// void test_setvbuf() {
//   char buf[1024];
//   memset(buf, '\0', sizeof(buf));

//   fprintf(stdout, "Start full buffer\n");
//   setvbuf(stdout, buf, _IOFBF, sizeof(buf));
//   fprintf(stdout, "This is a test code\n");
//   fprintf(stdout, "Hello\n");
//   fflush(stdout);

//   fprintf(stdout, "It will appear after 5 seconds\n");
//   sleep(5);
//   return;
// }

// void test_tmpfile() {
//   FILE* fp;
//   fp = tmpfile();
//   printf("Create temp file\n");
//   fclose(fp);
//   return;
// }

// void test_tmpnam() {
//   char* ptr;
//   char buffer[L_tmpnam];

//   tmpnam(buffer);
//   fprintf(stdout, "Create temp file name:%s\n", buffer);

//   ptr = tmpnam(NULL);
//   fprintf(stdout, "Clear tmp buffer:%s", ptr);
//   return;
// }

// void test_printf() {
//   int ch;

//   for (ch = 33; ch < 126; ++ch) {
//     printf("ASCII number:%d, Char:%c\n", ch, ch);
//   }
//   return;
// }

// void test_sprintf() {
//   char str[80];
//   memset(str, '\0', sizeof(str));

//   sprintf(str, "What about this\n");
//   puts(str);
//   return;
//}

// void WriteFrmtd(FILE* stream, char* format, ...) {
//   va_list args;

//   va_start(args, format);
//   vfprintf(stream, format, args);
//   va_end(args);
//   return;
// }

// void test_vfprintf() {
//   FILE* fp;

//   fp = fopen("file.txt", "w+");
//   WriteFrmtd(fp, "There are two arguments %d %s\n", 50, "people");
//   fclose(fp);
//   return;
// }

// void test_fgets() {
//   FILE* fp;
//   char str[50] = {0};

//   fp = fopen("file1.txt", "r");
//   if (!fp) {
//     printf("Open file error by mode ReadOnly\n");
//     perror("Error: ");
//     return;
//   }
//   if (fgets(str, sizeof(str), fp)) {
//     puts(str);
//   }
//   fclose(fp);
//   return;
// }

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* simple_memchr(const char* str, int c, size_t n) {
  if (!str) return NULL;
  while (n--) {
    if (*str++ == (char)c) {
      return (char*)str - 1;
    }
  }
  return NULL;
}

void test_memchr() {
  const char* str = "www.baidu.com";
  char* str1 = "wsw.alibaba.com";
  const char ch = '.';
  char* ret;
  char* str2;

  // ret = memchr(str, ch, strlen(str));
  ret = simple_memchr(str, ch, strlen(str));
  str2 = (char*)str1 - 1;
  printf("after |%c| is |%s|\n", ch, ret);
  printf("str1=%p str2=%p\n", str1, str2);
  printf("%c  %p\n", *str1++, str1);
  return;
}

int simple_memcmp(const char* s1, const char* s2, size_t n) {
  assert(s1 || s2);
  int ret = 0;
  while (n-- && (ret = *(unsigned char*)s1++ - *(unsigned char*)s2++) == 0)
    ;
  return ret;
}

void test_memcmp() {
  char str1[12] = "AAcdef";
  char str2[12] = "ABCDEF";
  int ret;
  int i = 0;

  // ret = memcmp(str1, str2, 6);
  // printf("i=%d\n", i++);
  // printf("s1=%p, s2=%p\n", str1, str2);
  // printf("s1=%p, s2=%p\n", &str1[0], &str2[0]);
  ret = simple_memcmp(str1, str2, 6);
  if (ret > 0) {
    printf("str1>str2\n");
  } else if (ret < 0) {
    printf("str1<str2\n");
  } else {
    printf("str1=str2\n");
  }
  return;
}

// memmove
void* simple_memcpy(char* dest, const char* src, size_t n) {
  assert(dest || src);
  char* ret = dest;
  if (src < dest) {
    dest += n;
    src += n;
    while (n--) *--dest = *--src;
  } else {
    while (n--) *dest++ = *src++;
  }
  return ret;
}

void test_memcpy() {
  char src[50] = "www.baidu.com";
  char dest[50] = {0};

  printf("Before:%s\n", dest);
  // memcpy(dest, src, strlen(src));
  simple_memcpy(dest, src, strlen(src));  // 1.281s
  printf("After:%s\n", dest);
  return;
}

void test_memmove() {
  char src[] = "new string";
  char dest[] = "old string";

  printf("Before:src=%s dest=%s\n", src, dest);
  memmove(dest, src, strlen(src));  // 0.24s 系统底层做了优化
  printf("After::src=%s dest=%s\n", src, dest);
}

void test_memset() {
  char str[50] = {0};

  strcpy(str, "This is string.h library function");
  puts(str);

  memset(str, '$', 7);
  puts(str);
  return;
}

void* simple_strcat(char* dest, const char* src) {
  assert(dest || src);
  char* ret = dest;
  while (*dest++ != '\0')
    ;
  --dest;
  while ((*dest++ = *src++) != '\0')
    ;
  return ret;
}

void test_strcat() {
  char src[50] = "This is source";
  char dest[50] = "This is destination";

  // strcat(dest, src);
  simple_strcat(dest, src);
  printf("Final string:|%s|", dest);
  return;
}

void test_strncat() {
  char src[50] = "This is source";
  char dest[50] = "This is destination";

  strncat(dest, src, 15);
  printf("Final string:|%s|", dest);
  return;
}

void* simple_strchr(const char* str, const char ch) {
  assert(str);

  while ((*str++ != ch) && (*str != '\0'))
    ;
  return (char*)--str;
}

void test_strchr() {
  const char str[] = "www.baidu.com";
  const char ch = '.';
  char* ret;

  // ret = simple_strchr(str, ch);
  ret = strchr(str, ch);
  printf("After|%c|is|%s|\n", ch, ret);
}

size_t simple_strcspn(const char* str, const char* rej) {
  assert(str || rej);
  char* s = (char*)str;
  char c;

  while ((c = *rej++) != '\0') {
    while (*str++ != '\0') {
      if (*rej == *str) return str - s;
    }
  }
  return str - s;
}

void test_strcspn() {
  char str1[] = "www.baidu.com";
  char str2[] = "ab12";
  int len;

  len = simple_strcspn(str1, str2);
  // len = strcspn(str1, str2);
  printf("len=%d\n", len);
  return;
}

void test_strpbrk() {
  const char str1[] = "https://www.baidu.com";
  const char str2[] = "ub";
  char* ret;

  ret = strpbrk(str1, str2);
  if (!ret) return;
  printf("first char appear is:%c\n", *ret);
  return;
}

void test_strspn() {
  int len;
  const char str1[] = "ABCDEFG012736";
  const char str2[] = "ABCDF2";

  len = strspn(str1, str2);
  printf("first match string length is:%d\n", len);
  return;
}

void* simple_strstr(const char* s1, const char* s2) {
  assert(s1 || s2);
  size_t i, j;
  size_t len1 = strlen(s1);
  size_t len2 = strlen(s2);
  if (len1 < len2) return NULL;

  for (i = 0; i <= len1 - len2; ++i) {
    for (j = 0; j < len2; ++j)
      if (s1[i + j] != s2[j]) break;
    if (j == len2) return (char*)s1 + i;
  }
  return NULL;
}

void test_strstr() {
  const char str1[] = "www.baidu.com";
  const char str2[] = "baidu";
  char* ret;

  ret = simple_strstr(str1, str2);
  // ret = strstr(str1, str2);
  if (!ret) return;
  printf("ret=%s\n", ret);
  return;
}

void test_string() {
  char str[] = "abc\0def\0";
  printf("str=%s\n", str);
  return;
}

char* simple_strtok_r(char* s, const char* delim, char** save_ptr) {
  char* end;
  if (s == NULL) {
    s = *save_ptr;
  }
  if (*s == '\0') {
    *save_ptr = s;
    return NULL;
  }
  s += strspn(s, delim);
  if (*s == '\0') {
    *save_ptr = s;
    return NULL;
  }
  end = s + strcspn(s, delim);
  if (*end == '\0') {
    *save_ptr = end;
    return s;
  }
  *end = '\0';
  *save_ptr = end + 1;
  return s;
}

char* simple_strtok(char* s, const char* delim) {
  static char* olds;
  return simple_strtok_r(s, delim, &olds);
}

void test_strtok() {
  char str[] = "www.baidu.com";
  char delim[] = ".";
  char* token;
  token = simple_strtok(str, delim);
  while (token) {
    printf("%s\n", token);
    token = simple_strtok(NULL, delim);
  }
  return;
}

void test_strxfrm() {
  char dest[20];
  char src[20];
  int len;

  strcpy(src, "baidu");
  len = strxfrm(dest, src, 20);
  printf("string |%s| length is |%d|", dest, len);
  return;
}

void test_asctime() {
  struct tm t;

  t.tm_sec = 10;
  t.tm_min = 06;
  t.tm_hour = 17;
  t.tm_mday = 7;
  t.tm_mon = 10;
  t.tm_year = 120;
  t.tm_wday = 6;

  puts(asctime(&t));
  return;
}

void test_clock() {
  clock_t start_t, end_t, total_t;
  int i;

  start_t = clock();
  printf("Startup, start_t=%ld\n", start_t);

  printf("Begin a resycle, start_t=%ld\n", start_t);
  for (i = 0; i < 10000000; ++i) {
  }
  end_t = clock();
  printf("End, end_t=%ld\n", end_t);

  total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
  printf("CPU time spend% f\n", total_t);
  printf("Exit\n");
  return;
}

void test_ctime() {
  time_t curtime;
  time(&curtime);
  printf("Current time:%s\n", ctime(&curtime));
  return;
}

void test_difftime() {
  time_t start_t, end_t;
  double diff_t;

  printf("Startup...\n");
  time(&start_t);

  printf("Sleep 5 seconds...\n");
  sleep(5);

  printf("End...\n");
  time(&end_t);

  diff_t = difftime(end_t, start_t);
  printf("Run time=%f\n", diff_t);
  return;
}

#define BST (+1)
#define CCT (+8)

void test_gmtime() {
  time_t rawtime;
  struct tm* info;

  time(&rawtime);
  info = gmtime(&rawtime);

  printf("Current world clock:\n");
  printf("Landon:%2d:%02d\n", (info->tm_hour + BST) % 24, info->tm_min);
  printf("China:%2d:%02d\n", (info->tm_hour + CCT) % 24, info->tm_min);
  return;
}

void test_localtime() {
  time_t rawtime;
  struct tm* info;

  time(&rawtime);
  info = localtime(&rawtime);
  printf("Local time is %s\n", asctime(info));
  return;
}

void test_mktime() {
  int ret;
  struct tm info;
  char buffer[80];

  info.tm_year = 120;
  info.tm_mon = 10;
  info.tm_mday = 8;
  info.tm_hour = 20;
  info.tm_min = 17;
  info.tm_sec = 30;
  info.tm_isdst = -1;

  ret = mktime(&info);
  if (ret == -1) {
    printf("mktime failed\n");
  } else {
    strftime(buffer, sizeof(buffer), "%c", &info);
    puts(buffer);
  }
  return;
}

void test_strftime() {
  char buffer[80];
  time_t rawtime;
  struct tm* info;

  time(&rawtime);
  info = localtime(&rawtime);

  strftime(buffer, sizeof(buffer), "%x-%I:%M%p", info);
  puts(buffer);
  return;
}

void test_time() {
  time_t seconds;

  seconds = time(NULL);
  printf("hours:%d\n", seconds / 3600);
  return;
}

void functionA() {
  printf("This is a exit function!\n");
  return;
}

void test_atexit() {
  atexit(functionA);
  printf("strat...\n");
  printf("end...\n");
  return;
}

void test_exit() {
  printf("start...\n");
  printf("exit\n");
  exit(0);
  printf("end...\n");
  return;
}

void test_getenv() {
  printf("PATH:%s\n", getenv("PATH"));
  printf("HOME:%s\n", getenv("HOME"));
  printf("ROOT:%s\n", getenv("ROOT"));
  return;
}

void test_system() {
  char command[50];
  strcpy(command, "dir");
  system(command);
  return;
}

int compfunc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

void test_bsreach() {
  int values[] = {2, 4, 28, 34, 45};
  int* item;
  int key = 28;
  item = bsearch(&key, values, 5, sizeof(int), compfunc);
  if (item) {
    printf("Found item=%d\n", *item);
  } else {
    printf("Item=%d can not be found!\n", *item);
  }
  return;
}

void test_qsort() {
  int i;
  int values[] = {29, 34, 1, 7, 16, 3};
  printf("Before sort:");
  for (i = 0; i < 6; ++i) {
    printf("%d\t", values[i]);
  }
  qsort(values, 6, sizeof(int), compfunc);
  printf("\nAfter sort:");
  for (i = 0; i < 6; ++i) {
    printf("%d\t", values[i]);
  }
  return;
}

void test_div() {
  div_t output;
  output = div(27, 4);
  printf("(27/4)Quotient=%d\n", output.quot);
  printf("(27/4)Remainder=%d\n", output.rem);
  return;
}

void test_rand_srand() {
  int i;
  // wchar_t wc = L"Hi";
  time_t t;
  srand((unsigned)time(&t));
  for (i = 0; i < 10; ++i) {
    printf("%d\t", rand() % 50);
  }
  return;
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
  // test_offsetof();
  // test_clearerr();
  // test_feof();
  // test_fflush();
  // test_fgetpos();
  // test_fread_fwrite();
  // test_fseek();
  // test_ftell();
  // test_remove();
  // test_rename();
  // test_rewind();
  // test_setbuf();
  // test_setvbuf();
  // test_tmpfile();
  // test_tmpnam();
  // test_printf();
  // test_sprintf();
  // test_vfprintf();
  // test_fgets();
  // test_memchr();
  // test_memcmp();
  // test_memcpy();
  // test_memmove();
  // test_memset();
  // test_strcat();
  // test_strncat();
  // test_strchr();
  // test_strcspn();
  // test_strpbrk();
  // test_strspn();
  // test_strstr();
  // test_string();
  // test_strtok();
  // test_strxfrm();
  // test_asctime();
  // test_clock();
  // test_ctime();
  // test_difftime();
  // test_gmtime();
  // test_localtime();
  // test_mktime();
  // test_strftime();
  // test_time();
  // test_atexit();
  // test_exit();
  // test_getenv();
  // test_system();
  // test_bsreach();
  // test_qsort();
  // test_div();
  // char values[] = {0, 1, 7, 9, 23};
  // printf("size of values is:%d %p %p\n", sizeof(values), &values,
  // &values[0]);
  // int a[9] = {0};
  // printf("%d\n", a[8]);
  // test_rand_srand();
  // int array[] = {1, 2, 3, 4, 5};
  // int pos = 1;
  // printf("%d\n%d\n", array[++pos], pos);
  // char* src = "ABC";
  // char dest[10];
  // memmove(dest, src, sizeof(src));
  // // dest[3] = 'D';
  // printf("sizeof(src)=%d, dest=%s\n", sizeof(src), dest);
  int srcArray[5];
  printf("%d\t%d\n", sizeof(srcArray), 5 * sizeof(int));
  return;
}
