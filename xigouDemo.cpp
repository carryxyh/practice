//
// Created by 修宇航 on 2017/12/19.
//

class Foo {
public:
    //析构函数，销毁成员
    ~Foo();
};

int main() {
    Sales_data *p = new Sales_data; //p是一个内置指针
    auto p2 = make_shred<Sales_data>(); //p2是一个shared_ptr
}