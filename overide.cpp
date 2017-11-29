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

typedef string::size_type sz;

//默认值
//注意：一旦某个参数被赋予了默认值，它后面的所有参数都必须有默认值
//调用时：只能省略靠右的参数 ex:screen(20) = screen(20,80,' ')
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ');

sz wd = 80;
char def = ' ';

sz ht();

string screen(sz = ht(), sz = wd, char = def);

void f2() {
    def = '*'; //改变了默认实参的值
    sz wd = 100;
    screen(); //调用screen(ht(),80,'*')
}

int main() {

}