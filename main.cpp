#include <iostream>

std::string global_str;
int global_int;

int main() {

//    std::cout << "Enter two numbers:" << std::endl;
//    int v1 = 0, v2 = 0;
//    std::cin >> v1 >> v2;
//    std::cout << "sum is " << v1 + v2 << std::endl;

    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;//32
    std::cout << u - u2 << std::endl;//这里必然是一个正数  4294967264

    std::cout << "---------------" << std::endl;

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl; //32
    std::cout << i - i2 << std::endl; //-32
    std::cout << i - u << std::endl; //这里把i变成无符号数 0
    std::cout << u - i << std::endl; //0

    std::cout << "---------------" << std::endl;

    long double ld = 3.1415926536;
    //这里会报错，因为可能丢失数据
//    int a{ld}, b = {ld};
//    std::cout << a << b << std::endl;

    //相比上面，这里没有报错，但是确实丢失了数据
    int c(ld), d = ld;
    std::cout << c << d << std::endl;

    std::cout << "---------------" << std::endl;

    int local_int;
    std::string local_str;
    std::cout << local_int << std::endl;
    std::cout << global_int << std::endl;
    std::cout << local_str << std::endl;
    std::cout << global_str << std::endl;

    std::cout << "---------------" << std::endl;

    //下面这三行代码会报错  注销掉第二行仍然报错。
//    extern int externi; //声明一个变量。这个时候只规定了类型和名字，没有申请存储空间或者初始值
//    int externi = 10;
//    std::cout << externi << std::endl;

    std::cout << "---------------" << std::endl;

    int sum;
    for (int j = 0; j < 10; ++j) {
        sum += j;
    }
    std::cout << "sum is " << sum << std::endl;

    std::cout << "---------------" << std::endl;

    int ii = 100, ss = 0;
    for (int ii = 0; ii != 10; ++ii) {
        ss += ii;
    }
    //这里输出 100 45  这里的ii是main里的ii  但是ss累加的ii是for循环中的
    std::cout << ii << "    " << sum << std::endl;

    return 0;
}