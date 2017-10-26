//
// Created by 修宇航 on 2017/10/26.
//
#include <iostream>

struct Foo {
}; //不加 ‘;’ 则报错
int main() {

    struct Sales_data {
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    } accum;

    //等价于下一句。 第二种写法比较好
    Sales_data accm;


    return 0;
}
