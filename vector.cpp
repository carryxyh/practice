//
// Created by 修宇航 on 2017/11/1.
//
#include <vector>

using namespace std; //使用标准库的命名空间中的vector

//vector中不能放引用  引用不是对象

int main() {

    vector<int> ivec; //跟java一样
    vector<int> v1;
    vector<int> v2(v1); //v2包含所有v1的元素 副本
    int a = 10;
    vector<int> v3(a, a);// 包含10个10
    vector<int> v4(a);//包含10个重复地执行初始化的对象
    vector<int> v5{1, 2}; //等价于 vector<int> v5 = {1,2}

    //push元素到vector中
    ivec.push_back(1);

    //以下含义和java近似
    ivec.empty();
    ivec.size();
    ivec[0];
    ivec == v1; //v1和v2相等  当且仅当它们的元素数量相同而且对应位置的元素值相同

    //不能对一个空的vector使用 vector[x] = val

    return 0;
}