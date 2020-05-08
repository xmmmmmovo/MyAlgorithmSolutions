//
// Created by xmmmmmovo on 2020/5/8.
//
#include <iostream>
#include <vector>

using namespace std;

template<typename it>
void it_func() {
    // 获取模板类型某个函数返回值
    decltype(declval<it>().begin()) tp;
    return;
}

int  f1() { return 0; }
int &f2() {
    int x = 0;
    return x;
}
int &&f3() { return 0; }

int main() {
    decltype(auto) x1 = f1();// x1 is int
    decltype(auto) x2 = f2();// x2 is int&
    decltype(auto) x3 = f3();// x3 is int&&

    it_func<vector<int>>();

    return 0;
}