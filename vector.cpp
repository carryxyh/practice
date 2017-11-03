//
// Created by 修宇航 on 2017/11/1.
//
#include <vector>
#include <string>

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

    //迭代器
    auto b = ivec.begin(); //b标识ivec的第一个元素
    auto e = ivec.end(); //e标识ivec的最后一个元素  b、e类型相同

    //*iter 返回迭代器所指元素的引用
    //iter -> mem 解引用iter并获取该元素的名为mem的成员，等价于 (*iter).mem
    //++iter 令iter指向容器中的下一个元素
    //--iter 令iter指向容器中的上一个元素
    //iter1 == iter2 两个迭代器是否相等 如果两个迭代器指向的是同一个元素，或者他们是同一个容器的尾后迭代器，则相等。

    //ex
    string s("some string");
    if (s.begin() != s.end()) {
        auto it = s.begin(); //it 标识 some中的s
        *it = toupper(*it); // 将当前字符改成大写
    }

    return 0;
}