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

    Sales_data obj(); //正确：定义了一个函数而不是对象
//    obj.isbn(); 错误：obj是一个函数`

    Sales_data item;
    string null_book = "9-999-9999-9";

    //这里发生了隐式转换。因为Sales_data有一个只有string作为入参的构造函数，我们需要使用Sales_data的地方，可以用string或者istream作为替代
    //combine参数是一个常量引用，所以我们可以给该参数传递一个临时量.这里的null_book被转成Sales_data tmp(null_book)
    item.combine(null_book);
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

    //ci 和 ri 都必须被初始化，因此我们没有为它们提供构造函数初始值的话将报错
    const int ci;
    int &ri;
};

//正确：显示的初始化引用和const成员
ConstRef::ConstRef(int ii) : i(ii), ci(ii), ri(ii) {}

//下面这个函数是错误的 报错
ConstRef::ConstRef(int ii) {
    i = ii; //正确
    ci = ii; //错误：不能给const赋值
    ri = i; //错误：ri没被初始化
}

class Sales_data2 {
public:
    //非委托构造函数使用对应的实参初始化成员
    Sales_data2(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}

    //其余构造函数全部委托给另一个构造函数
    Sales_data2() : Sales_data2("", 0, 0) {}

    Sales_data2(std::string s) : Sales_data2(s, 0, 0) {}

    Sales_data2(std::istream &is) : Sales_data2() {
        read(is, *this);
    }

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

//没有默认构造函数
class NoDefault {
public:
    NoDefault(const std::string &);
};

struct A {
    NoDefault my_mem;
};
A a; //错误：不能为A合成构造函数

struct B {
    B() {} //错误：b_member没有初始值
    NoDefault b_member;
};