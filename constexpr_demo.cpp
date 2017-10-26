//
// Created by 修宇航 on 2017/10/25.
//

int j = 0;
constexpr int i = 42; //i的类型是整型常量
int main() {
    const int max_files = 20; //max_files是常量表达式
    const int limit = max_files + 1; //limit是常量表达式
    int staff_size = 27; //staff_size不是常量表达式
//    const int sz = get_size(); //sz不是常量表达式，因为运行时才会获取

    constexpr int mf = 20; //20是常量表达式
    constexpr int limit2 = mf + 1; //mf + 1是常量表达式
//    constexpr int sz = size(); //只有当size函数是一个constexpr函数时，才是一个正确的声明语句

    //以下两句运行时出错，因为testi不是常量表达式。const int testi = 42则正确
//    int testi = 42;
//    constexpr int testOne = testi + 1;

    const int *intp = nullptr; //p是一个指向整型常量的指针
    constexpr int *q = nullptr; //q是一个指向整数的常量指针
    //intp 和 q 差别：p是一个指向常量的指针，而q是一个常量指针，其中的关键在于 constexpr 把它所定义的对象置为了顶层const  顶层const：指针本身是个常量

    //与其他常量指针类似，constexpr指针既可以指向常量，也可以指向一个非常量
    constexpr int *np = nullptr; //np是一个指向整数的常量指针，值为空

    // i j 都必须定义在函数体之外，不注释下面两句，而注释main上面定义的两句  则报错
//    int j = 0;
//    constexpr int i = 42; //i的类型是整型常量

    constexpr const int *p = &i; //p是常量指针 指向整型常量i
    constexpr int *p1 = &j; //p1是常量指针，指向整数j

//    int null = 0, *poi = null;
    int null = 0;
//    int *poi = null; //错误：不能把int变量直接赋值给指针！
    int poi = null; //正确

    return 0;
}