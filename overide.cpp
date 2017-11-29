//
// Created by 修宇航 on 2017/11/29.
//

#include "string"

using namespace std;

string read();

void print(const string &);

void print(double); //重载print函数

void fooBar(int ival) {
    bool read = false; //新作用域：隐藏了外层的read
    string s = read(); //错误：read是一个boolean，不是函数
    //通常不在局部作用域中声明函数
    void print(int); //新作用域：隐藏了之前的print
    print("Value : "); //错误：print(const string &)被隐藏掉了
    print(ival); //正确：当前print(int)可见
    print(3.14); //正确：调用print(int); print(double)被隐藏了
}

int main() {

}