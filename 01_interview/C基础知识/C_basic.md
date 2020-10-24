<!--
 * @Descripttion: 
 * @version: 
 * @Author: Allen Zhuang
 * @Date: 2020-10-16 03:59:08
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-10-24 08:54:41
-->
# C standard <assert.h>
简介
C 标准库的 assert.h头文件提供了一个名为 assert 的宏，它可用于验证程序做出的假设，并在假设为假时输出诊断消息。
已定义的宏 assert 指向另一个宏 NDEBUG，宏 NDEBUG 不是 <assert.h> 的一部分。如果已在引用 <assert.h> 的源文件中定义 NDEBUG 为宏名称，则 assert 宏的定义如下：
1.#define assert(ignore) ((void)0)
库宏
下面列出了头文件 assert.h 中定义的唯一的函数：
序号    函数 & 描述
1       void assert(int expression) //这实际上是一个宏，不是一个函数，可用于在 C 程序中添加诊断。

    C 库宏 - assert()
    描述
        C 库宏 void assert(int expression) 允许诊断信息被写入到标准错误文件中。换句话说，它可用于在 C 程序中添加诊断。
    声明
        下面是 assert() 宏的声明。
        1.void assert(int expression);
    参数
        expression -- 这可以是一个变量或任何 C 表达式。如果 expression 为 TRUE，assert() 不执行任何动作。如果 expression 为 FALSE，assert() 会在标准错误 stderr 上显示错误消息，并中止程序执行。
    返回值
        这个宏不返回任何值。
    实例
        下面的实例演示了 assert() 宏的用法。
        ```C
        #include <assert.h>
        #include <stdio.h>
        
        void main(void){
            int a;
            char str[50];

            printf("请输入一个整数值： ");
            scanf("%d\n", &a);
            assert(a >= 10);
            printf("输入的整数是： %d\n", a);
                
            printf("请输入字符串： ");
            scanf("%s\n", &str);
            assert(str != NULL);
            printf("输入的字符串是： %s\n", str);
        }
        ```
        
# C standard <ctype.h>
简介
C 标准库的 ctype.h 头文件提供了一些函数，可用于测试和映射字符。
这些函数接受 int 作为参数，它的值必须是 EOF 或表示为一个无符号字符。
如果参数 c 满足描述的条件，则这些函数返回非零（true）。如果参数 c 不满足描述的条件，则这些函数返回零。
库函数
下面列出了头文件 ctype.h 中定义的函数：
序号    函数 & 描述
1 int isalnum(int c)
该函数检查所传的字符是否是字母和数字。 
2 int isalpha(int c)
该函数检查所传的字符是否是字母。 
3 int iscntrl(int c)
该函数检查所传的字符是否是控制字符。 
4 int isdigit(int c)
该函数检查所传的字符是否是十进制数字。 
5 int isgraph(int c)
该函数检查所传的字符是否有图形表示法。（除了空白字符比如‘ ’以外所有可打印的字符） 
6 int islower(int c)
该函数检查所传的字符是否是小写字母。 
7 int isprint(int c)
该函数检查所传的字符是否是可打印的。 （可打印字符是非控制字符的字符）
8 int ispunct(int c)
该函数检查所传的字符是否是标点符号字符。 (标点符号字符可以是非字母数字（正如isalnum中的一样）的任意图形字符（正如isgraph中的一样）)
9 int isspace(int c)
该函数检查所传的字符是否是空白字符。 
10 int isupper(int c)
该函数检查所传的字符是否是大写字母。 
11 int isxdigit(int c)
该函数检查所传的字符是否是十六进制数字。 
标准库还包含了两个转换函数，它们接受并返回一个 "int"

序号    函数 & 描述
1 int tolower(int c)
该函数把大写字母转换为小写字母。 
2 int toupper(int c)
该函数把小写字母转换为大写字母。 

字符类
序号    字符类 & 描述
1 数字
完整的数字集合 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 } 
2 十六进制数字
集合 { 0 1 2 3 4 5 6 7 8 9 A B C D E F a b c d e f } 
3 小写字母
集合 { a b c d e f g h i j k l m n o p q r s t u v w x y z }  
4 大写字母
集合 {A B C D E F G H I J K L M N O P Q R S T U V W X Y Z } 
5 字母
小写字母和大写字母的集合 
6 字母数字字符
数字、小写字母和大写字母的集合 
7 标点符号字符
集合 ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~ 
8 图形字符
字母数字字符和标点符号字符的集合 
9 空格字符
制表符、换行符、垂直制表符、换页符、回车符、空格符的集合。 
10 可打印字符
字母数字字符、标点符号字符和空格字符的集合。 
11 控制字符
在 ASCII 编码中，控制字符的ASCII编码介于0x00(NUL)和0x1f(US)之间，以及0x7f(DEL)，某些平台的特定编译器实现还可以在扩展字符集(0x7f以上)中定义额外的控制字符。 
12 空白字符
包括空格符和制表符。 
13 字母字符
小写字母和大写字母的集合。 

C 标准库 - <errno.h>


简介

C 标准库的 errno.h 头文件定义了整数变量 errno，它是通过系统调用设置的，在错误事件中的某些库函数表明了什么发生了错误。该宏扩展为类型为 int 的可更改的左值，因此它可以被一个程序读取和修改。

在程序启动时，errno 设置为零，C 标准库中的特定函数修改它的值为一些非零值以表示某些类型的错误。您也可以在适当的时候修改它的值或重置为零。

errno.h 头文件也顶了以一系列表示不同错误代码的宏，这些宏应扩展为类型为 int 的整数常量表达式。

库宏

下面列出了头文件 errno.h 中定义的宏：


序号

宏 & 描述

1 extern int errno
这是通过系统调用设置的宏，在错误事件中的某些库函数表明了什么发生了错误。 
2 EDOM Domain Error
这个宏表示一个域错误，它在输入参数超出数学函数定义的域时发生，errno 被设置为 EDOM。 
3 ERANGE Range Error
这个宏表示一个范围错误，它在输入参数超出数学函数定义的范围时发生，errno 被设置为 ERANGE。 


C 标准库 - <float.h>


简介

C 标准库的 float.h 头文件包含了一组与浮点值相关的依赖于平台的常量。这些常量是由 ANSI C 提出的，这让程序更具有可移植性。在讲解这些常量之前，最好先弄清楚浮点数是由下面四个元素组成的：


组件    组件描述
S 符号 ( +/- ) 
b 指数表示的基数，2 表示二进制，10 表示十进制，16 表示十六进制，等等... 
e 指数，一个介于最小值 emin 和最大值 emax 之间的整数。 
p 精度，基数 b 的有效位数 

基于以上 4 个组成部分，一个浮点数的值如下：
floating-point = ( S ) p x b<sup>e</sup>
或
floating-point = (+/-) precision x base<sup>exponent</sup>


库宏

下面的值是特定实现的，且是通过 #define 指令来定义的，这些值都不得低于下边所给出的值。请注意，所有的实例 FLT 是指类型 float，DBL 是指类型 double，LDBL 是指类型 long double。


宏 描述
FLT_ROUNDS 定义浮点加法的舍入模式，它可以是下列任何一个值： 
-1 - 无法确定
0 - 趋向于零
1 - 去最近的值
2 - 趋向于正无穷
3 - 趋向于负无穷

FLT_RADIX 2 这个宏定义了指数表示的基数。基数 2 表示二进制，基数 10 表示十进制，基数 16 表示十六进制。 

FLT_MANT_DIG

DBL_MANT_DIG

LDBL_MANT_DIG
 这些宏定义了 FLT_RADIX 基数中的位数。 

FLT_DIG 6

DBL_DIG 10

LDBL_DIG 10
 这些宏定义了舍入后不会改变表示的十进制数字的最大值（基数 10）。 

FLT_MIN_EXP

DBL_MIN_EXP

LDBL_MIN_EXP
 这些宏定义了基数为 FLT_RADIX 时的指数的最小负整数值。 

FLT_MIN_10_EXP -37

DBL_MIN_10_EXP -37

LDBL_MIN_10_EXP -37
 这些宏定义了基数为 10 时的指数的最小负整数值。 

FLT_MAX_EXP

DBL_MAX_EXP

LDBL_MAX_EXP
 这些宏定义了基数为 FLT_RADIX 时的指数的最大整数值。 

FLT_MAX_10_EXP +37

DBL_MAX_10_EXP +37

LDBL_MAX_10_EXP +37
 这些宏定义了基数为 10 时的指数的最大整数值。 

FLT_MAX 1E+37

DBL_MAX 1E+37

LDBL_MAX 1E+37
 这些宏定义最大的有限浮点值。 

FLT_EPSILON 1E-5

DBL_EPSILON 1E-9

LDBL_EPSILON 1E-9
 这些宏定义了可表示的最小有效数字。 

FLT_MIN 1E-37

DBL_MIN 1E-37

LDBL_MIN 1E-37
 这些宏定义了最小的浮点值。 

实例

下面的实例演示了 float.h 文件中定义的一些常量的使用。
#include <stdio.h>
#include <float.h>
 
int main()
{
   printf("The maximum value of float = %.10e\n", FLT_MAX);
   printf("The minimum value of float = %.10e\n", FLT_MIN);
 
   printf("The number of digits in the number = %.10e\n", FLT_MANT_DIG);
}


让我们编译和运行上面的程序，这将产生下列结果：
1.The maximum value of float = 3.4028234664e+38
2.The minimum value of float = 1.1754943508e-38
3.The number of digits in the number = 7.2996655210e-312

C 标准库 - <limits.h>


简介

limits.h 头文件决定了各种变量类型的各种属性。定义在该头文件中的宏限制了各种变量类型（比如 char、int 和 long）的值。
这些限制指定了变量不能存储任何超出这些限制的值，例如一个无符号可以存储的最大值是 255。

库宏
下面的值是特定实现的，且是通过 #define 指令来定义的，这些值都不得低于下边所给出的值。

宏  值  描述
CHAR_BIT  8 定义一个字节的比特数。 
SCHAR_MIN -128 定义一个有符号字符的最小值。 
SCHAR_MAX 127 定义一个有符号字符的最大值。 
UCHAR_MAX  255 定义一个无符号字符的最大值。 
CHAR_MIN 0 定义类型 char 的最小值，如果 char 表示负值，则它的值等于 SCHAR_MIN，否则等于 0。 
CHAR_MAX 127 定义类型 char 的最大值，如果 char 表示负值，则它的值等于 SCHAR_MAX，否则等于 UCHAR_MAX。 
MB_LEN_MAX  1 定义多字节字符中的最大字节数。 
SHRT_MIN -32768 定义一个短整型的最小值。 
SHRT_MAX  +32767 定义一个短整型的最大值。 
USHRT_MAX  65535 定义一个无符号短整型的最大值。 
INT_MIN  -32768 定义一个整型的最小值。 
INT_MAX  +32767 定义一个整型的最大值。 
UINT_MAX 65535 定义一个无符号整型的最大值。 
LONG_MIN  -2147483648 定义一个长整型的最小值。 
LONG_MAX  +2147483647 定义一个长整型的最大值。 
ULONG_MAX  4294967295 定义一个无符号长整型的最大值。 

实例

下面的实例演示了 limit.h 文件中定义的一些常量的使用。
#include <stdio.h>
#include <limits.h>
 
int main()
{
 
   printf("The number of bits in a byte %d\n", CHAR_BIT);
 
   printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
   printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
   printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);
 
   printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
   printf("The maximum value of SHORT INT = %d\n", SHRT_MAX); 
 
   printf("The minimum value of INT = %d\n", INT_MIN);
   printf("The maximum value of INT = %d\n", INT_MAX);
 
   printf("The minimum value of CHAR = %d\n", CHAR_MIN);
   printf("The maximum value of CHAR = %d\n", CHAR_MAX);
 
   printf("The minimum value of LONG = %ld\n", LONG_MIN);
   printf("The maximum value of LONG = %ld\n", LONG_MAX);
  
   return(0);
}


让我们编译和运行上面的程序，这将产生下列结果：
1.The number of bits in a byte 8
2.The minimum value of SIGNED CHAR = -128
3.The maximum value of SIGNED CHAR = 127
4.The maximum value of UNSIGNED CHAR = 255
5.The minimum value of SHORT INT = -32768
6.The maximum value of SHORT INT = 32767
7.The minimum value of INT = -32768
8.The maximum value of INT = 32767
9.The minimum value of CHAR = -128
10.The maximum value of CHAR = 127
11.The minimum value of LONG = -2147483648
12.The maximum value of LONG = 2147483647

C 标准库 - <locale.h>


简介

locale.h 头文件定义了特定地域的设置，比如日期格式和货币符号。接下来我们将介绍一些宏，以及一个重要的结构 struct lconv 和两个重要的函数。

库宏

下面列出了头文件 locale.h 中定义的宏，这些宏将在下列的两个函数中使用：


序号

宏 & 描述

1  LC_ALL
设置下面的所有选项。 
2  LC_COLLATE
影响 strcoll 和 strxfrm 函数。 
3  LC_CTYPE
影响所有字符函数。 
4  LC_MONETARY
影响 localeconv 函数提供的货币信息。 
5  LC_NUMERIC
影响 localeconv 函数提供的小数点格式化和信息。 
6  LC_TIME
影响 strftime 函数。 

库函数

下面列出了头文件 locale.h 中定义的函数：


序号

函数 & 描述

1 char *setlocale(int category, const char *locale)
设置或读取地域化信息。 
2 struct lconv *localeconv(void)
设置或读取地域化信息。 

库结构
typedef struct {
  char *decimal_point;
  char *thousands_sep;
  char *grouping;	
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
} lconv


以下是各字段的描述：


序号

字段 & 描述

1  decimal_point
用于非货币值的小数点字符。 
2  thousands_sep
用于非货币值的千位分隔符。 
3  grouping
一个表示非货币量中每组数字大小的字符串。每个字符代表一个整数值，每个整数指定当前组的位数。值为 0 意味着前一个值将应用于剩余的分组。 
4  int_curr_symbol
国际货币符号使用的字符串。前三个字符是由 ISO 4217:1987 指定的，第四个字符用于分隔货币符号和货币量。 
5  currency_symbol
用于货币的本地符号。 
6  mon_decimal_point
用于货币值的小数点字符。 
7  mon_thousands_sep
用于货币值的千位分隔符。 
8  mon_grouping
一个表示货币值中每组数字大小的字符串。每个字符代表一个整数值，每个整数指定当前组的位数。值为 0 意味着前一个值将应用于剩余的分组。 
9  positive_sign
用于正货币值的字符。 
10  negative_sign
用于负货币值的字符。 
11  int_frac_digits
国际货币值中小数点后要显示的位数。 
12  frac_digits
货币值中小数点后要显示的位数。 
13  p_cs_precedes
如果等于 1，则 currency_symbol 出现在正货币值之前。如果等于 0，则 currency_symbol 出现在正货币值之后。 
14  p_sep_by_space
如果等于 1，则 currency_symbol 和正货币值之间使用空格分隔。如果等于 0，则 currency_symbol 和正货币值之间不使用空格分隔。 
15  n_cs_precedes
如果等于 1，则 currency_symbol 出现在负货币值之前。如果等于 0，则 currency_symbol 出现在负货币值之后。 
16  n_sep_by_space
如果等于 1，则 currency_symbol 和负货币值之间使用空格分隔。如果等于 0，则 currency_symbol 和负货币值之间不使用空格分隔。 
17  p_sign_posn
表示正货币值中正号的位置。 
18  n_sign_posn
表示负货币值中负号的位置。 

下面的值用于 p_sign_posn 和 n_sign_posn:

值  描述

0  封装值和 currency_symbol 的括号。 
1  放置在值和 currency_symbol 之前的符号。 
2  放置在值和 currency_symbol 之后的符号。 
3  紧挨着放置在值和 currency_symbol 之前的符号。 
4  紧挨着放置在值和 currency_symbol 之后的符号。 

C 标准库 - <math.h>

简介

math.h 头文件定义了各种数学函数和一个宏。在这个库中所有可用的功能都带有一个 double 类型的参数，且都返回 double 类型的结果。

库宏

下面是这个库中定义的唯一的一个宏：


序号

宏 & 描述

1  HUGE_VAL

当函数的结果不可以表示为浮点数时。如果是因为结果的幅度太大以致于无法表示，则函数会设置 errno 为 ERANGE 来表示范围错误，并返回一个由宏 HUGE_VAL 或者它的否定（- HUGE_VAL）命名的一个特定的很大的值。

如果结果的幅度太小，则会返回零值。在这种情况下，error 可能会被设置为 ERANGE，也有可能不会被设置为 ERANGE。
 

库函数

下面列出了头文件 math.h 中定义的函数：


序号

函数 & 描述

1 double acos(double x)
返回以弧度表示的 x 的反余弦。 
2 double asin(double x)
返回以弧度表示的 x 的反正弦。 
3 double atan(double x)
返回以弧度表示的 x 的反正切。 
4 double atan2(double y, double x)
返回以弧度表示的 y/x 的反正切。y 和 x 的值的符号决定了正确的象限。 
5 double cos(double x)
返回弧度角 x 的余弦。 
6 double cosh(double x)
返回 x 的双曲余弦。 
7 double sin(double x)
返回弧度角 x 的正弦。 
8 double sinh(double x)
返回 x 的双曲正弦。 
9 double tanh(double x)
返回 x 的双曲正切。 
10 double exp(double x)
返回 e 的 x 次幂的值。 
11 double frexp(double x, int *exponent)
把浮点数 x 分解成尾数和指数。返回值是尾数，并将指数存入 exponent 中。所得的值是 x = mantissa * 2 ^ exponent。 
12 double ldexp(double x, int exponent)
返回 x 乘以 2 的 exponent 次幂。 
13 double log(double x)
返回 x 的自然对数（基数为 e 的对数）。 
14 double log10(double x)
返回 x 的常用对数（基数为 10 的对数）。 
15 double modf(double x, double *integer)
返回值为小数部分（小数点后的部分），并设置 integer 为整数部分。 
16 double pow(double x, double y)
返回 x 的 y 次幂。 
17 double sqrt(double x)
返回 x 的平方根。 
18 double ceil(double x)
返回大于或等于 x 的最小的整数值。 
19 double fabs(double x)
返回 x 的绝对值。 
20 double floor(double x)
返回小于或等于 x 的最大的整数值。 
21 double fmod(double x, double y)
返回 x 除以 y 的余数。 

