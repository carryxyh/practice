//
// Created by 修宇航 on 2017/11/29.
//

#include "string"

using namespace std;

bool lengthCompare(const string &, const string &);

void ff(int *);

void ff(unsigned int);

//这里这个pf就是指向函数的指针
//下面两句等价
void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &));

void useBigger(const string &s1, const string &s2, bool (*pf)(const string &, const string &));

//入参是int 返回值是一个函数指针
//下面两句等价，第一句太复杂了 使用第二句
int (*f1(int))(int *, int);

//后面部分是返回值
auto f1(int) -> int (*)(int *, int);

int main() {

    //pf前面有*说明pf是指针，右侧是形参列表，表示指向的是函数，左侧，发现函数的返回值是布尔值
    //不写括号，则pf是一个返回bool指针的函数 bool *pf(const string &, const string &)是一个返回bool *的函数
    bool (*pf)(const string &, const string &);

    //我们把函数名作为一个值使用时，自动把函数变成地址
    //以下两句等价 取地址符是可选的
    //指向函数时，需要函数和指针的 形参一致 返回值一致
    pf = lengthCompare;
    pf = &lengthCompare;

    bool b1 = pf("hello", "goodbye"); //调用lengthCompare函数
    bool b2 = (*pf)("hello", "goodbye"); //跟上一句一样

    //指向重载函数，这时必须精确匹配 void (*pf2)(int) = ff;错误 double (*pf3)(int *) 错误，不匹配
    void (*pf1)(unsigned int) = ff; //pf1 指向void ff(unsigned int);

}