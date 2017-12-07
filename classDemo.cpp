//
// Created by 修宇航 on 2017/12/4.
//

#include <iostream>
#include "Sales_data.h"

using namespace std;

//在类的外部定义成员函数，必须加上所属的类名
//double Sales_data::avg_price() const {
//    if (units_sold)
//        return revenue / units_sold;
//    else
//        return 0;
//}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this; //返回调用该函数的对象
}

//print和read接收的都是普通引用，因为要对流和对象进行修改
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum; //返回 sum 的副本
}

//在类的外部定义构造函数
Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}

int main() {
    Sales_data total;
    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "No data ?!" << endl;
    }

    Screen::pos ht = 24, wd = 80;
}

class A {

    using Unit = std::vector<int>::size_type;
};

class B {
    A::Unit a;
};

class ConstRef {
public:
    ConstRef(int ii);

private:
    int i;
    const int ci;
    int &ri;
};