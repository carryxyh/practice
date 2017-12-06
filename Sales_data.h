//
// Created by 修宇航 on 2017/10/31.
//

#ifndef SALES_DATA_H //当且晋档变量未定义时为真
#define SALES_DATA_H //把一个名字设为预处理变量

#include <string>
#include "vector"

using namespace std;

//class 和 struct ：class可以在它的第一个访问说明符之前定义成员，访问权限依赖于类定义的方式
//                  struct则定义在第一个访问说明符之前的成员是public，使用class则为private
// 使用class还是struct：所有成员都是public用struct否则用class
//struct Sales_data {
class Sales_data {

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    double avg_price() const {
        if (units_sold)
            return revenue / units_sold;
        else
            return 0;
    }


public:
    //下面的四个都是构造函数
    //default 默认构造函数
    Sales_data() = default;

    Sales_data(const string &s) : bookNo(s) {};

    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}

    Sales_data(std::istream &);

    //这里isbn后面的const的作用：使得函数中使用的this是一个常量
    std::string isbn() const {

//        return this->bookNo;等价于下面那句 this是一个常量指针，指向这个对象
        return bookNo;
    }

    Sales_data &combine(const Sales_data &);
};

Sales_data add(const Sales_data &, const Sales_data &);

std::ostream &print(std::ostream &, const Sales_data &);

std::istream &read(std::istream &, Sales_data &);

#endif //SALES_DATA_H

//声明一个函数，还未定义
void print(vector<int>::const_iterator beg, vector<int>::const_iterator end);