//
// Created by 修宇航 on 2017/10/31.
//

#ifndef SALES_DATA_H //当且晋档变量未定义时为真
#define SALES_DATA_H //把一个名字设为预处理变量

#include <string>
#include "vector"

using namespace std;

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif //SALES_DATA_H

//声明一个函数，还未定义
void print(vector<int>::const_iterator beg, vector<int>::const_iterator end);