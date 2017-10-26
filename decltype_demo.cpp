//
// Created by 修宇航 on 2017/10/26.
//
#include <iostream>

int main() {
//    decltype(f()) sum = x; //sum的类型，就是f的返回类型。但是这里不会执行f函数

    const int ci = 0, &cj = ci;
    decltype(ci) x = 0; //x的类型是const int
    decltype(cj) y = x; //y的类型是const int &，y绑定到变量x
    decltype(cj) z; //错误：z是引用，必须初始化
    //引用从来都作为其所指对象的同义词出现，只有在decltype处例外：decltype会用这个引用作为类型

    int i = 42, *p = &i, &r = i;

    //r是一个引用，因此decltype(r)的结果是引用类型。如果想让结果类型是r所指的类型，可以把r作为表达式的一部分，如r+0，显然这个表达式的结果将是一个具体值而非引用
    decltype(r + 0) b; //正确：加法的结果是int，因此b是一个（未初始化）int

    //表达式内容是解引用操作，则decltype将得到引用类型 *p 的类型就是int&，并不是int
    decltype(*p) c; //错误：c是int &，必须初始化

    //decltype的表达式如果是加上了括号的变量，结果将是引用
    decltype((i)) d; //错误：d是int &，必须初始化

    //test
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;

    std::cout << c << "    " << d << std::endl; //4  4
    std::cout << a << std::endl; //4
    return 0;
}