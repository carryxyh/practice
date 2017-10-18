#include <iostream>

int main() {

//    std::cout << "Enter two numbers:" << std::endl;
//    int v1 = 0, v2 = 0;
//    std::cin >> v1 >> v2;
//    std::cout << "sum is " << v1 + v2 << std::endl;

    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;//32
    std::cout << u - u2 << std::endl;//这里必然是一个正数  4294967264

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl; //32
    std::cout << i - i2 << std::endl; //-32
    std::cout << i - u << std::endl; //这里把i变成无符号数 0
    std::cout << u - i << std::endl; //0

    long double ld = 3.1415926536;
    //这里会报错，因为可能丢失数据
//    int a{ld}, b = {ld};
//    std::cout << a << b << std::endl;

    //相比上面，这里没有报错，但是确实丢失了数据
    int c(ld), d = ld;
    std::cout << c << d << std::endl;

    return 0;
}