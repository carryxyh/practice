//
// Created by 修宇航 on 2017/11/10.
//

#include <string>

using namespace std;

/**
 * 以下四个都是c风格字符串的函数：
 * strlen  返回字符串长度，不计算空字符串
 * strcmp  两个字符串是否相等。s1 == s2 返回0；s1 > s2 正值
 * strcat(s1,s2)  s2附加给s1，返回s1
 * strcpy(s1,s2)  s2拷贝给s1，返回s1
 *
 * @return
 */
int main() {
    string s = "hello world!";

    char c[] = {'C', '+', '+'}; //不以空字符串结尾
    strlen(c); //严重错误：c没有以空字符串结尾，从c的内存地址向前寻找一直找到空字符串


    string s1 = "A string example";
    string s2 = "A different string";
    if (s1 < s2) {
        //false: s2 < s1
    }

    //c风格字符串
    const char c1[] = "A string example";
    const char c2[] = "A different string";
    //当使用数组时，实际上使用的是数组首个元素的地址 -> 指向首个元素的指针
    if (c1 < c2) { //未定义的：比较两个无关的地址
        //应该使用:
        strcmp(c1, c2);
    }

    return 0;
}