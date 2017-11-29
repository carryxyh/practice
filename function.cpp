//
// Created by 修宇航 on 2017/11/23.
//

#include "iostream"

using std::string;
using std::initializer_list;

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

//function(int &arr[10])  和  function(int (&arr)[10])
//第一个：包含十个引用的数组 错误
//第二个：具有十个整数的整形数组的引用 正确

//可变形参只能放在最后一个
void multiParam(...);

/**
 * 函数完成以后，所占的存储空间将被释放，因此函数结束意味着局部变量的引用将指向不再有效的内存区域
 * 总而言之，不要反悔局部对象的引用或指针
 */
const string &mainip() {
    string ret;
    if (!ret.empty())
        return ret; //错误，返回局部变量的引用
    else
        return "Empty"; //错误，"Empty"是一个局部临时变量
}

int (*func(int i))[10];
//func(int i) 表示调用func函数需要一个int类型的参数
//(*func(int i))意味着我们可以对函数func调用的结果执行解引用操作
//(*func(int i))[10]表示解引用func的调用将得到一个大小是10的数组
//int (*func(int i))[10] 表示数组中的元素是int类型

//auto func(int i) -> int(*)[10];这种方式等价于上面这种 可以清楚的看到入参和出参 出参是一个指向含有是个整数的数组

//const_cast在重载中的应用
//第一个shorterString函数，可以传入两个非常量string引用，单结果是const string的引用
const string &shorterString(const string &s1, const string &s2) {
    return s1.size() <= s2.size() ? s1 : s2;
}

//当它的参数不是常量时，得到的结果是一个普通的引用
string &shorterString(string &s1, string &s2) {
    //这个r是一个cosnt string的引用，但是本来是绑定在一个普通引用上
    auto &r = shorterString(const_cast<const string &>(s1), const_cast<const string &>(s2));
    //这里强转是安全的
    return const_cast<string &>(r);
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

    //数组的两个特殊性质对我们定义和使用作用在数组上的函数有影响，这两个性质是：
    //1.不允许拷贝数组
    //2.使用数组时，通常会将其转换成指针

    //----------------------------------------------------------------------------
    //如果一个函数的入参数量不定，但是类型一样，可以用这个list
    //lst中的值全都是常量，无法改变其中的值
    initializer_list<int> lst;
}

