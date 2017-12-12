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

    //编译器只允许一次类型转换，这种就是错误的
    item.combine("abcabc-abc-abcde");
    //正确
    item.combine(string("abcabc-abc-abcde"));
    //正确
    item.combine(Sales_data("abcabc-abc-abcde"));

    //正确，static_cast可以使用explicit的构造函数
    item.combine(static_cast<Sales_data>(cin));

    //可以用这种花括号的方式初始化聚合类
    //值的顺序要按照成员的顺序
    Data dat = {0, "Anna"};
    //错误的 Data dat2 = {"Anna", 0};


    //constexpr表达式的构造函数用于生成constexpr对象以及constexpr函数的参数或返回类型
    constexpr Debug io_sub(false, true, false);

}

/**
 * 聚合类：
 * 1.所有成员都是public的
 * 2.没有定义任何构造函数
 * 3.没有类内初始值
 * 4.没有基类，也没有virtual函数
 */
struct Data {
    int ival;
    string s;
};

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

class Debug {
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}

    //constexpr构造函数必须既符合构造函数要求（不能包含返回值）又符合constexpr函数的要求（意味着它拥有的唯一可执行的语句就是返回语句）
    //所以一般constexpr 构造函数都是空的
    //constexpr必须初始化所有的成员，初始值或者使用constexpr构造函数，或者是一条常量表达式
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}

    constexpr bool any() { return hw || io || other; }

private:
    bool hw;
    bool io;
    bool other;
};