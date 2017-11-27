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

//字符结尾有一个空字符
void print(const char *cp) {
    if (cp) //若cp不是一个空指针
        while (*cp) //只要指针所指的字符不是空字符
            cout << *cp++; //输出当前字符 并将指针向前移动一个位置
}

bool is_sentence(const string &s) {
    string::size_type ctr = 0;
    //如果 find_char 的第一个参数类型是 string& 那么下面这句调用会发生编译时错误 因find_char只能接受普通引用
    //如果不能改动find_char的入参，需要在is_sentence内部定义一个string类型的变量，让其等于s的副本，然后把这个string传递给find_char
    return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}

//尽管形式不同，但三个print的函数等价 每一个print都有一个const int*的形参
//void print(const int*);
//void print(const int[]);
//void print(const int[10]);
//当调用 print 的时候 只检查入参是否是 const int*
//int i=0,j[2] = {0,1}
// print(&i) 和 print(j) 都正确


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

    //数组的两个特殊性质对我们定义和使用作用在数组上的函数有影响，这两个性质是：
    //1.不允许拷贝数组
    //2.使用数组时，通常会将其转换成指针
}

