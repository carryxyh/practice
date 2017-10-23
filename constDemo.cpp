//
// Created by 修宇航 on 2017/10/20.
//

/**
 * 引用的类型必须与其所引用对象的类型一致，但是又两个例外：
 *  1.初始化常量引用时，允许用任意表达式作为初始值，只要该表达式的结果能转换成引用的类型即可
 *
 * @return
 */
#include <iostream>

int main() {
    const int ci = 1024;
    const int &r1 = ci; //正确：引用及其对应的对象都是常量

//    r1 = 42;//错误：r1是常量引用
//    int &r2 = ci;  //错误：试图让一个非常量引用指向一个常量对象

    //1.demo
    int i = 42;
    const int &ri = i; //允许将const int&绑定到一个普通的int对象上
    const int &ri2 = 42; //正确：ri2是一个常量引用
    const int &ri3 = ri * 2; //正确：ri3是一个常量引用
//    int &ri4 = ri * 2; //错误：ri4是一个普通的非常量引用

    double dd = 3.14;
    const int &rd = dd;
    //以上两句等价于：
//    const int temp = dd; 由double生成一个临时的整型变量
//    const int &rd = temp; 让rd绑定这个临时量
    //如果 rd 不是常量引用，为什么就不能绑定到int 引用上：rd不是常量，就允许对rd赋值，这样就会改变rd所引用的对的的值。注意，此时绑定的对象是一个临时量而不是dd！
    //既然让rd引用dd，就肯定想通过rd改变dd的值，否则干嘛要给rd赋值呢？所以c++把这种行为规定为非法

    //注意：常量引用仅对引用可参与的操作做出了限定，对于引用本身是不是一个常量不做限定！由于对象可能是非常量，所以允许通过其他途径改变它的值
    int testi = 42;
    int &testri1 = testi;
    const int &testri2 = testi;
    std::cout << testi << "    " << testri2 << std::endl; // 42  42
    testi = 0;
    std::cout << testi << "    " << testri2 << std::endl; // 0  0
    testri2 = 10; // 错误 testri2 是常量引用

    const double pi = 3.14;
    double *ptr = &pi;// 错误：ptr是一个普通指针
    const double *cptr = &pi; //正确：cptr可以指向一个双精度常量
    *cptr = 42;//错误：不能给*cptr赋值

    //指针的类型必须与其所指对象的类型一致，有两个例外：
    //1.允许一个指向常量的指针指向一个非常量对象
    double dvava = 3.14;
    cptr = &dvava; //正确：但是不能通过cptr改变dvava的值 下面语句是错误的
    *cptr = 314;
    //指向常量的指针也没有规定其所指的对象必须是一个常量。指向常量的指针仅仅要求不能通过该指针改变对象的值，没有规定那个对象的值不能通过其他途径改变

    return 0;
}
