<!--
 * @Descripttion: 
 * @version: 
 * @Author: Allen Zhuang
 * @Date: 2020-10-16 03:59:08
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-10-21 17:17:18
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

