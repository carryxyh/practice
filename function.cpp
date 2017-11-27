//
// Created by 修宇航 on 2017/11/23.
//

#include "iostream"

using std::string;

using std::cout;
using std::endl;

//注意这个函数要定义在 main 函数上面，定义在下面是不行的！
size_t count_calls() {
    //这个函数结束后，这个ctr的值依然有效，下次调用这个方法，会从ctr目前的值开始加
    static size_t ctr = 0;
    return ++ctr;
}

void reset(int &i) {
    i = 0;
}

//这里入参const 则不能修改i的值
void testConst(const int i) {
//    i = 10;
}

string::size_type find_char(const string &s, char c, string::size_type &occurs) {
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size()) {
                ret = i;
            }
            ++occurs;
        }
    }
    return ret;
}

string::size_type find_char2(string &s, char c, string::size_type &occurs) {
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size()) {
                ret = i;
            }
            ++occurs;
        }
    }
    return ret;
}

bool is_sentence(const string &s) {
    string::size_type ctr = 0;
    //如果 find_char 的第一个参数类型是 string& 那么下面这句调用会发生编译时错误 因find_char只能接受普通引用
    //如果不能改动find_char的入参，需要在is_sentence内部定义一个string类型的变量，让其等于s的副本，然后把这个string传递给find_char
    return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}

int main() {

    for (size_t i = 0; i != 10; i++) {
        cout << count_calls() << endl;
    }

    int r = 0;
    int &ref = r;
    reset(ref);
    cout << r << endl; //这里输出0，因为ref就算r，ref是r的别名，实际穿进去就算r

    string::size_type ctr;
    string::size_type ret = find_char("Hello World", 'o', ctr);
    cout << ret << "   " << ctr << endl;

    //如果 find_char的第一个参数不是const string &s 而是 string &s 则下面这句编译报错
    //我们要把不会改变的参数定义成 const 的
//    string::size_type ret2 = find_char2("Hello World", 'o', ctr);


}

