//
// Created by 修宇航 on 2017/10/20.
//

/**
 * 引用的类型必须与其所引用对象的类型一致，但是又两个例外：
 *  1.初始化常量引用时，允许用任意表达式作为初始值，只要该表达式的结果能转换成引用的类型即可
 *
 * @return
 */
int main() {
    const int ci = 1024;
    const int &r1 = ci; //正确：引用及其对应的对象都是常量

    r1 = 42;//错误：r1是常量引用
    int &r2 = ci;  //错误：试图让一个非常量引用指向一个常量对象

    //1.demo
    int i = 42;
    const int &ri = i; //允许将const int&绑定到一个普通的int对象上
    const int &ri2 = 42; //正确：ri2是一个常量引用
    const int &ri3 = ri * 2; //正确：ri3是一个常量引用
    int &ri4 = ri * 2; //错误：ri4是一个普通的非常量引用

    double dd = 3.14;
    const int &rd = dd;
    //以上两句等价于：
//    const int temp = dd; 由double生成一个临时的整型变量
//    const int &rd = temp; 让rd绑定这个临时量
    //如果 rd 不是常量引用，为什么就不能绑定到int 引用上：rd不是常量，就允许对rd赋值，这样就会改变rd所引用的对的的值。注意，此时绑定的对象是一个临时量而不是dd！
    //既然让rd引用dd，就肯定想通过rd改变dd的值，否则干嘛要给rd赋值呢？所以c++把这种行为规定为非法

    return 0;
}
