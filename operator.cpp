//
// Created by 修宇航 on 2017/11/21.
//

#include "iostream"

int main() {
    int *p;
    decltype(*p); //这里是 int& 指向int的引用
    decltype(&p); //这里是 int**指向整数指针的指针

    int ia[] = {0, 2, 4, 6, 8};
    int last = *(ia + 4); // last = 8
    last = *ia + 4; //last = 4

    std::cout << *ia << std::endl; //0
    std::cout << ia << std::endl; //地址

    int i = 0;
    std::cout << i << "  " << ++i << std::endl; //<<运算符没有规定顺序，可能先 i 后 ++i 也可能返回来
    return 0;
}