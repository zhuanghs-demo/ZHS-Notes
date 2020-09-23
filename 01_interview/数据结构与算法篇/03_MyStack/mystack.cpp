/*
 * @Descripttion: stack
 * @version: V1.00
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-09-22 14:01:22
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-09-22 19:20:21
 */
#include"mystack.h"

typedef  long   __int64;

//递归实现
void convert_recursion(myStack<char>& S, __int64 n, int base)
{
    static char digit[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    if(n > 0){
        convert_recursion(S, n/base, base);
        S.push(digit[n%base]);
    }
}

//迭代实现
void convert_iteration(myStack<char>& S, __int64 n, int base)
{
    static char digit[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(n > 0){
        int remainder = (int)(n%base);
        S.push(digit[remainder]);
        n = n/base;
    }
}

//栈混洗判断表达式括号是否合法
bool paren(const char exp[])
{
    myStack<char> S;
    for(int i = 0; exp[i]; i++){
        switch (exp[i]){
        case '(':
        case '[':
        case '{':
            S.push(exp[i]);
            break;
        case ')':
            if(S.empty() || '(' != S.pop()) return false;
            break;
        case ']':
            if(S.empty() || '[' != S.pop()) return false;
            break;
        case '}':
            if(S.empty() || '{' != S.pop()) return false;
            break;
        default:
            break;
        }
    }
    return S.empty();
}

