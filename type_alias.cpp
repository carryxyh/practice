//
// Created by 修宇航 on 2017/10/26.
//

#include <iostream>
int main() {

    typedef double wages; //wages 是double的同义词
    typedef wages base, *p; //base是double的同义词，p是double*的同义词

    using S = std::string;
    //using int = i; 错误。只能用来定义类型

    wages hourly; //等价于 double hourly

    typedef char *pstring;
    const pstring cstr = 0; //cstr 是指向char的常量指针
    const pstring *ps; //ps是一个指针，它的对象是指向char的常量指针

    //pstring实际上是指向char的指针，因此，const pstring就是指向char的常量指针，而并非是指向常量的指针
    //const pstring cstr != const char *cstr

    return 0;
}