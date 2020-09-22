/*
 * @Descripttion: stack
 * @version: V1.00
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-09-22 11:19:25
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-09-22 15:00:57
 */
#include<vector>

template<typename T>
class myStack:public vector<T>
{
public:
    void push(const T& e) {insert(size(), e);}
    T pop() {return remove(size() - 1);}
    T& top() {return (*this)[size() - 1];}
};

