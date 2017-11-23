//
// Created by 修宇航 on 2017/11/23.
//

#include "iostream"

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

int main() {

    for (size_t i = 0; i != 10; i++) {
        cout << count_calls() << endl;
    }

    int r = 0;
    int &ref = r;
    reset(ref);
    cout << r << endl; //这里输出0，因为ref就算r，ref是r的别名，实际穿进去就算r
}

