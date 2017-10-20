//
// Created by 修宇航 on 2017/10/20.
//

int main() {
    const int ci = 1024;
    const int &r1 = ci; //正确：引用及其对应的对象都是常量

    r1 = 42;//错误：r1是常量引用
    int &r2 = ci;  //错误：视图让一个非常量引用指向一个常量对象
    return 0;
}
