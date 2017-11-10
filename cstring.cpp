//
// Created by 修宇航 on 2017/11/10.
//

#include <string>

using namespace std;

/**
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
    return 0;
}