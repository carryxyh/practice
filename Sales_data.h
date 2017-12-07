//
// Created by 修宇航 on 2017/10/31.
//

#ifndef SALES_DATA_H //当且晋档变量未定义时为真
#define SALES_DATA_H //把一个名字设为预处理变量

#include <string>
#include "vector"

using namespace std;

//class 和 struct ：class可以在它的第一个访问说明符之前定义成员，访问权限依赖于类定义的方式
//                  struct则定义在第一个访问说明符之前的成员是public，使用class则为private
// 使用class还是struct：所有成员都是public用struct否则用class
//struct Sales_data {
class Sales_data {

    //为Sales_data的非成员函数所做的友元声明
    //因为这三个函数中 直接使用了形如Sales_data.bookNo的访问方式
    //友元的作用：允许其他类或者函数访问它的非公有（private）成员，并且友元不是类的成员，也不受所在区域访问控制级别的约束
    //在这里声明之后，还需要在别的地方声明函数，否则是无法定义函数的！及类外面必须有 Sales_data add(const Sales_data &, const Sales_data &) 的声明
    friend Sales_data add(const Sales_data &, const Sales_data &);

    friend std::ostream &print(std::ostream &, const Sales_data &);

    friend std::istream &read(std::istream &, Sales_data &);

public:
    //下面的四个都是构造函数
    //default 默认构造函数 如果有其他构造函数，则本函数是必须的
    Sales_data() = default;

    Sales_data(const string &s) : bookNo(s) {};

    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}

    Sales_data(std::istream &);

    //这里isbn后面的const的作用：使得函数中使用的this是一个常量
    std::string isbn() const {

//        return this->bookNo;等价于下面那句 this是一个常量指针，指向这个对象
        return bookNo;
    }

    Sales_data &combine(const Sales_data &);

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    double avg_price() const {
        if (units_sold)
            return revenue / units_sold;
        else
            return 0;
    }
};

Sales_data add(const Sales_data &, const Sales_data &);

std::ostream &print(std::ostream &, const Sales_data &);

std::istream &read(std::istream &, Sales_data &);

class Window_mgr {

public:
    using ScreenIndex = std::vector<Screen>::size_type;

    void clear(ScreenIndex);

private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};

};

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

class Screen {

    //Window_mgr的成员可以访问Screen的私有部分
    friend class Window_mgr;

    //函数成员友元，只有clear中能访问Screen的私有部分
    friend void Window_mgr::clear(Window_mgr::ScreenIndex);

public:

    typedef std::string::size_type pos;
    //using pos = std::string::size_type; 和上面一句等价

    Screen() = default;

    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; } //隐式内联

    inline char get(pos ht, pos wd) const; //显示内联 这个get重载了上面一个get

    Screen &move(pos r, pos c); //能在之后被设为内联

    void some_member() const;

    Screen &set(char);

    Screen &set(pos, pos, char);

    //Screen myScreen(5,3);
    //const Screen blank(5,3);
    //myScreen.set('#').display(cout); //调用非常量版本
    //blank.display(cout); //调用常量版本
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    mutable size_t access_ctr; //即使在一个const对象内也能被修改

    void do_display(std::ostream &os) const { os << contents; }
};

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

//如果返回的是Screen 不是 Screen & 则返回的是Screen的值的拷贝
inline Screen &Screen::set(pos r, pos col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}

// some_member 是一个const成员函数，它艺人能够改变access_ctr的值。access_ctr是可变成员，const函数都可以改变它的值
void Screen::some_member() const {
    ++access_ctr;
}

struct X {
    friend void f() {}

    X() { f(); } //错误 f还没声明

    void g();

    void h();
};

void X::g() { return f(); } //错误，这里f也没声明

void f();

void X::h() { return f(); } //正确，f声明了

#endif //SALES_DATA_H

//声明一个函数，还未定义
void print(vector<int>::const_iterator beg, vector<int>::const_iterator end);