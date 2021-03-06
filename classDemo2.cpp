//
// Created by 修宇航 on 2017/12/12.
//

#include "string"

class Account {
public:
    //成员函数不用通过作用域运算符就能直接访问静态成员
    void calculate() { amount += amount * interestRate; }

    //静态成员函数不能声明成const的，而且我们也不能在static函数体内使用this指针
    static double rate() { return interestRate; }

    static void rate(double);

private:
    std::string owner;
    double amount;
    static double interestRate;

    static double initRate();

    static constexpr int period = 30; // period是常量表达式

    double daily_tbl[period];
};

//这里不能重复static关键字！
void Account::rate(double newRate) {
    interestRate = newRate;
}

//这里即使不定义initRate函数，下面：double Account::interestRate = initRate(); 这句依然有效
//double Account::initRate() {
//    return 3.14;
//}

//定义了名为interestRate的对象，对象是类Account的静态成员 类型是double
//从  Account::  开始后面的部分都位于Account的作用域之内了，因此我们可以直接使用initRate函数，注意这是私有的函数！
//interestRate也可以访问类的私有成员
//这句话不能放在函数里。报错
double Account::interestRate = initRate();

//Bar1是个不完全类型 指向Bar1的指针是合法的，但是Bar1的对象是不合法的
class Bar1;

class Bar {
public:
    //我们可以使用静态成员作为默认实参,非静态不行
    Bar &clear(char = bkground);

private:
    static Bar mem1; //正确：静态成员可以是不完全类型
    Bar *mem2; //正确：指针成员可以说不完全类型
    Bar mem3; //错误：数据成员必须是完全类型

    static const char bkground;
};

int main() {
    double r;
    //直接用作用域运算符访问
    r = Account::rate();

    Account ac1;
    Account *ac2 = &ac1;

    r = ac1.rate(); //通过对象或引用
    r = ac2->rate(); //通过指向对象的指针
}