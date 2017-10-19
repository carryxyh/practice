//
// Created by 修宇航 on 2017/10/19.
//
#include "iostream"

/**
 * 引用并非对象，只是一个已经存在的对象的另外一个名字
 * 引用不是对象，不能定义引用的引用
 */
int main() {

    int ival = 1024;
    int &refVal = ival;
//    int &refVal2; 这里这句会报错，引用必须有初始值
    refVal = 2;

    //这里会输出 2  对refVal进行的操作都是在原来的对象即ival上的
    std::cout << ival << std::endl;

    int ii = refVal;
    //这里输出2
    std::cout << ii << std::endl;

    //正确 refVal3绑定到了那个与refVal绑定的对象上，这里就是ival
    int &refVal3 = refVal;
    std::cout << refVal3 << std::endl; //2

    //利用与refVal绑定的对象的值初始化变量i
    int i = refVal; // 正确 i=ival;
    std::cout << i << std::endl; //2

    return 0;
}