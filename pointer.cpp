//
// Created by 修宇航 on 2017/10/19.
//
#include "iostream"
#include "cstdlib"

/**
 * 指针和引用区别：
 * 引用本身不是对象，一旦定义了引用，就无法再绑定到另外的对象
 * 指针赋值就是指向了另外的地址
 *
 * @return
 */
int main() {
    double dval;
    double *pd = &dval; //正确：初始值是double型对象的地址
    double *pd2 = pd; //正确：初始值是指向double对象的指针

    std::cout << pd << std::endl;
    std::cout << pd2 << std::endl;
    //以上两句输出值相同，都是dval的地址

//    int *pi = pd; //错误：指针pi和pd类型不匹配
//    pi = &dval; //错误：试图把double型对象的地址赋给int型指针

    int *pn = nullptr; //等价于int *pn = 0;
    std::cout << pn << std::endl; // 0x0

    int *p2 = 0; // 直接将p2初始化为字面常量0

    int *p3 = NULL; //等价于int *p3 = 0; 现在不推荐 最好都是用nullptr
    std::cout << p3 << std::endl; // 0x0

    int zero = 0;
    int *pi;
//    pi = zero; //错误：不能把int变量直接赋值给指针！

    int ival = 1024;
    int *pival = 0;
    int *pival2 = &ival;
    if (pival);// false 指针值为0（不指向任何对象的时候）false
    if (pival2); // true

    //指针 == 指针  返回true：二者存放的地址相同
    // 地址相同有三种：1.都为空 2.都指向同一对象 3.都指向了同一个对象的下一个地址  注意：一个指针指向某对象，同事另一个指针指向另外对象的下一个地址，此时也有可能两个指针值相同，即指针相同

    double obj = 3.14, *pobj = &obj;//正确：void* 能存放任意类型对象的地址
    void *pvoid = &obj; //obj可以是任何类型的对象
    pvoid = pobj; //pvoid可以存放任意类型的指针

    //pointer point to ref
    int i = 42;
    int *po;  //p是一个int型指针
    int *&r = po; //r是一个对指针p的引用   解读r的类型 从右向左阅读r。离r最近的符号是&，所以r是引用 *说明r引用的是一个指针  最后int说明r引用的是int类型的指针

    r = &i; //r引用了一个指针，因此给r赋值&i就是让po指向i
    *r = 21; //解引用r得到i，也就是po指向的对象，将i的值改为0  这里的 *r 等价于 *int指针
    std::cout << i << std::endl;

    return 0;
}