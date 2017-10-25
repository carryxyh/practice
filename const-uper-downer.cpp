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

    i = ci;// 正确，ci是一个顶层const
    p2 = p3;//正确：p2和p3指向的对象类型相同，p3顶层const的部分不影响

    //底层const限制不能忽视，当执行对象的拷贝时，拷入和拷出的对象必须具有相同的底层const资格，或者两个对象的数据类型能够转换。一般来说，非常量可以转换成常量，反之不行
    int *p = p3;//p3包含底层const的定义，而p没有
    p2 = p3;//正确：p2和p3都是底层const
    p2 = &i;//正确：int*能转换成const int *
    int &r = ci;//错误：普通的int&不能绑定到int常量上
    const int &r2 = i;//正确：const int&可以绑定到一个普通int值上


    return 0;
}
