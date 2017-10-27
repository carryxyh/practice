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
    } data1;

    //等价于下一句。 第二种写法比较好
    Sales_data data2;

    double price = 0;
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;

    return 0;
}
