//
// Created by 修宇航 on 2017/11/6.
//

#include <string>

using namespace std;


int main() {
    const char a4[6] = "Daniel"; //错误：尽管字面值 Daniel看起来只有六个字符，但是必须数组长度至少为7，六个放字面量，一个放空字符
    int a[] = {0, 1, 2};//正确
//    int a2[] = a; //错误：不允许使用一个数组初始化另外一个数组
//    a2 = a; //错误：不能把一个数组直接赋值给另一个数组

    int arr[4] = {0, 1, 2}; //等价于int arr[4] = {0, 1, 2, 0};

    int *parr[42]; //含有42个整型指针的数组
//    int &refs[10] = ?; //错误：不存在引用的数组
    int (*Parray)[4] = &arr; //parray指向一个含有4个整数的数组
    int (&arrRef)[4] = arr; //arrRef引用一个含有10个整数的数组
//    int *(&arrRefPtr)[10] = ptrs; //arrRefPtr是数组的引用，该数组含有十个指针

    string nums[] = {"one", "two", "threee"};
    string *p = &nums[0];
    string *p2 = nums; //编译器会自动地将其替换为一个指向数组首元素的指针  这句话等价于：string *p2 = &nums[0];

    int ia[] = {0, 1, 2};
//    auto ia2(ia123);  ia2是一个整型指针，指向ia的第一个元素 //ia2 = 42 错误：ia2是一个指针，不能用int给指针赋值
//    上面一句等价于：auto ia2(&ia[0]);

    decltype(ia) ia3 = {0, 1, 2}; //decltype(ia)返回的类型是由10个整数构成的数组

    int *beg = begin(ia); //指向ia的首元素的指针
    int *las = end(ia); //指向ia尾元素的下一位置的指针
    //循环找第一个负数
    while (beg != las && *beg >= 0)
        beg++;

    //指针运算------------------------------------------------

    //给一个指针加上（减去）某整数，结果仍是指针，新指针指向的元素与原来的指针相比前进了（后退了）该整数值个位置：
    constexpr size_t sz = 5;
    int arrp[sz] = {1, 2, 3, 4, 5};
    int *pc = arrp; //等价于 int *pc = &arrp[0]
    int *pc2 = pc + 4; //ip2指向arrp的尾元素arrp[4]

    //允许解引用
    int last = *(pc + 4); //last = 5

    auto n = end(arrp) - begin(arrp); //n的值5，也就是arr中元素的数量
    //n的类型是 ptrdiff_t 的标准库类型（带符号），和size_t一样

    int iii = 0, szzz = 42;
    int *ppp = &iii, *eee = &szzz;
    //ppp 和 eee 毫无关系，比较二者无意义
    //两个空指针相减，结果为0
    while (ppp < eee) {

    }


    return 0;
}