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

    //错误 初始值必须是对象
//    int &refVal4 = 10;
//    double dval = 3.14;
//    int &refVal = dval; //错误 此处引用类型的初始值必须是int对象

    int iii = 1, &r1 = iii;
    //正确
    double d = 0.1, &r2 = d;

    //正确
    r1 = d;

    std::cout << iii << "   " << r1 << "    " << d << "   " << r2 << std::endl; // 1 1 0.1 0.1

    r2 = r1;

    std::cout << iii << "   " << r1 << "    " << d << "   " << r2 << std::endl; // 1 1 1 1

    iii = r2;

    std::cout << iii << "   " << r1 << "    " << d << "   " << r2 << std::endl; // 1 1 1 1

    r1 = d;

    std::cout << iii << "   " << r1 << "    " << d << "   " << r2 << std::endl; // 1 1 1 1

    //test
    int err = 1, &refff = err;
    double errd = 0.1, &refffd = errd;
    //这样赋值是正确的
    refff = errd;

    std::cout << err << std::endl; //0  0.1自动被转化成了0

    //test
    int testi, &testRef = testi;
    testi = 5;
    testRef = 10;
    std::cout << testi << "   " << testRef << std::endl; // 10  10


    return 0;
}