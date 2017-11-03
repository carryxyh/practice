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
    //iter1 - iter2 他们之间的距离

    //ex
    string s("some string");
    if (s.begin() != s.end()) {
        auto it = s.begin(); //it 标识 some中的s
        *it = toupper(*it); // 将当前字符改成大写
    }

    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) {
        *it = toupper(*it);
    }

    //------------------------------------------
    vector<int>::iterator iterator1; //iterator1能读写vector<int>的元素
    string::iterator iterator2; //iterator2能读写string对象中的字符
    vector<int>::const_iterator iterator3; //iterator3只能读元素，不能写元素
    string::const_iterator iterator4; //iterator4只能读字符，不能写字符
    //如果一个string或者vector是常量，则只能使用const_iterator

    //begin 和 end 返回的具体类型由对象是否是常量决定，对象是常量，begin和end返回const_vector，否则返回iterator
    auto itconst = ivec.cbegin(); //直接返回const_iterator
    //iter -> empty() 等价于 (*iter).empty()  *iter.empty()是错误，这个相当于运行iterator的empty方法

    //使用了迭代器的循环体，都不能向迭代器所属的容器中添加元素

    //--------------------------------------------

    //要查找10
    int search = 10;

    //必须有序，无序需要排序
    vector<int> order_vec;
    auto beg = order_vec.begin(), end = order_vec.end();
    auto mid = order_vec.begin() + (end - beg) / 2; //中间点

    while (mid != end && *mid != search) {
        if (search < *mid) {
            end = mid;
        } else
            beg = mid + 1;
        mid = beg + (end - beg) / 2;
    }

    return 0;
}