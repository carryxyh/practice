//
// Created by 修宇航 on 2017/11/1.
//
#include <string>
#include <iostream>

using std::string;

int main() {
    string s1; //默认初始化
    string s2 = s1; //s2是s1的副本
    string s3 = "hiya"; //s3是该字符串字面值的副本  拷贝初始化
    string s4(10, 'c'); //cccccccccc 直接初始化
    string s5 = string(10, 'c'); //拷贝 这个string是临时对象用于拷贝

    //------------------------------------

//    os << s s写到输出流os当中，返回os
//    is >> s 从is中读取字符串赋给s，字符串以空白分割，返回is
//    getline(is,s) 从is读取一行赋给s，返回is
    //其他操作与 java 类似  s.empty();空返回true s.size s[n] s1+s2 s1=s2 s1==s2大小写敏感

    //c++不支持如下写法：
//    string sss = "hello" + " world";

    //引用处理字符串
    string string1("hello world");
    for (auto &c : string1) {
        c = toupper(c); //c是一个引用，赋值语句改变string1中的字符的值
    }
    std::cout << string1 << std::endl;

    return 0;
}