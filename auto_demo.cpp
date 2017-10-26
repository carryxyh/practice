//
// Created by 修宇航 on 2017/10/26.
//

#include <iostream>

/**
 * 对常量对象取地址是一种底层const
 * 即指向的对象是一个常量
 */

int main() {

    int val1 = 1;
    double val2 = 3.14;
    auto item = val1 + val2; //由val1和val2相加的结果可以推断出item的类型
    //auto定义的变量必须有初始值

    std::cout << item << std::endl;

    auto i = 0, *p = &i; //正确：i是整数、p是整型指针
//    auto sz = 0, pi = 3.14; //错误：sz和pi类型不一致

    /*------------------------------------------------------------*/

    int &r = i;
    auto a = r; //a是一个整数（r是i的别名，而i是一个整数） 此时编译器以饮用对象的类型作为auto的类型

    /*------------------------------------------------------------*/


    int i = 0, &r = i;
    //auto一般会忽略顶层const，同时底层const会保留下来
    const int ci = i, &cr = ci;
    std::cout << cr << std::endl; //0

    auto b = ci; //b是一个整数  ci顶层const被忽略了
    auto c = cr; //c是一个整数  cr是ci的别名，ci本身是一个顶层const
    auto d = &i; //d是一个整型指针 整数的地址就是指向整数的指针

    int *p = &i;

    std::cout << &i << std::endl;
    std::cout << d << std::endl;
    std::cout << p << std::endl; // d == &i == p

    auto e = &ci; //e是一个指向整数常量的指针 const int *

    //如果希望推断出auto类型是一个顶层const 需要明确指出：
    const auto f = ci; // ci的推演类型是int f是const int

    auto &g = ci; //g是一个整型常量引用，绑定ci
    auto &h = 42; //错误：不能为非常量引用绑定字面值
    const auto &j = 42; //正确：可以为常量引用绑定字面值

    /*------------------------------------------------------------*/

    auto k = ci, &l = i; //k整数 l整型引用
    auto &m = ci, *p = &ci; //m是对整型常量的引用  p是指向整型常量的指针
    auto &n = i, *p2 = &ci; //错误：i类型是int 而&ci的类型是const int


    return 0;
}

