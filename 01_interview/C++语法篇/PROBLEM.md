##### const的作用
1、修饰变量，说明该变量不能被修改
2、修饰指针，分为指向常量的指针（pointer to const）和自身是常量的指针（常量指针，const pointer）
3、修饰引用，指向常量的引用（reference to const），用于形参类型，避免参数拷贝，也避免函数对值得修改
4、修饰成员函数，经修饰的成员函数不能改变其成员变量，以供常量对象进行调用

##### const的指针与引用
    *指针
        *指向常量的指针（pointer to const）
        *自身是常量的指针（const pointer）
    *引用
        *指向常量的指针（reference to const）
        *没有const reference，因为引用本身就是const pointer

##### static的作用

##### 指针与引用的区别
