//
// Created by 修宇航 on 2017/10/19.
//

#include <iostream>

int reused = 42; //全局作用域
int main() {

//    reused = 32;//这里输出32  已经把全局的覆盖了
    std::cout << reused << std::endl;


    int unique = 0;
    std::cout << reused << "     " << unique << std::endl; // 42 0

    int reused = 10;
    std::cout << reused << "     " << unique << std::endl; // 10 0

    // :: 符号 -> 作用域操作符 全局作用域没有名称 所以 ::reused 使用了全局的reused变量
    // 这里我们就知道了，main函数中的reused并不会覆盖全局的变量
    std::cout << ::reused << "     " << unique << std::endl; // 42 0

    return 0;
};

