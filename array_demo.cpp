//
// Created by 修宇航 on 2017/11/6.
//

#include <string>

using std::string;

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

    return 0;
}