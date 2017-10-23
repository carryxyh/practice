//
// Created by 修宇航 on 2017/10/23.
//

int main() {

    //顶层const：指针本身是个常量  底层const：指针所指的对象是一个常量
    //顶层const：任意的对象是常量  底层const：与指针和引用等复合类型的基本类型部分有关。
    //指针类型既可以是顶层const 也可以是 底层const

    int i = 0;
    int *const p1 = &i; //指针本身是常量 不能改变p1的值，但是可以改变 *p1 的值
    *p1 = 10; //正确

    const int ci = 42;//不能改变ci的值

    const int *p2 = &ci; //底层const 允许改变p2 但是不能改变 *p2
//    *p2 = 42; //运行时出错
//    p2 = &i; //正确

    const int *const p3 = p2; //靠右的const是顶层const  靠左的是底层const

    int twenty = 20;
    const int &r = twenty; //声明引用的const都是底层const 正确，允许将const int&绑定到一个普通的int对象上

    //const int &ref 是一个常量引用：引用的对象是一个常量

    const int thirty = 30;
//    r = thirty; //错误


    return 0;
}
