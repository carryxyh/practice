//
// Created by 修宇航 on 2017/11/21.
//

#include "iostream"
#include "Sales_data.h"
#include "vector"

using namespace std;

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

    // p->size() 等价于 (*p).size()
    // *p.size() 运行p.size（） 然后对结果解引用

    //sizeof 运算符
    Sales_data data, *pointer;
    sizeof(Sales_data); //存储Sales_data类型的对象所占的空间大小
    sizeof data; //data的类型的大小 及sizeof(Sales_data)
    sizeof pointer; //指针所占的空间大小
    sizeof *pointer; //pointer所指类型的空间大小，及sizeof(Sales_data)
    sizeof data.revenue; //Sales_data的revenuec成员对应类型的大小
    sizeof Sales_data::revenue; //另一种获取revenue大小的方式

    //sizeof 对数组进行处理时  不会把数组处理成指针
    //sizeof 对string或者vector对象执行，返回该类型固定部分的大小，并不是对象中的元素占用了多少空间
    constexpr size_t sz = sizeof(ia) / sizeof(*ia); //返回数组中有多少元素

    return 0;
}