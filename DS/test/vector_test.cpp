//
// Created by xmmmmmovo on 2020/5/8.
//
#include "../include/ds/vector.hpp"
#include <iostream>

using ds::vector;

struct LifetimeLogger {
    LifetimeLogger() { std::puts("default c'tor"); }
    ~LifetimeLogger() noexcept { std::puts("d'tor"); }
    LifetimeLogger(const LifetimeLogger &) { std::puts("copy c'tor"); }
    LifetimeLogger(LifetimeLogger &&) noexcept { std::puts("move c'tor"); }
    LifetimeLogger &operator=(const LifetimeLogger &) {
        std::puts("copy operator=");
        return *this;
    }
    LifetimeLogger &operator=(LifetimeLogger &&) noexcept {
        std::puts("move operator=");
        return *this;
    }
};

int main(int argc, char *argv[]) {
    vector<int> v;

    for (int i = 0; i < 2000; ++i) {
        v.emplace_back(i);
        std::cout << "cap is : " << v.capacity() << std::endl;
    }

    vector<LifetimeLogger> vl;

    vl.emplace_back(LifetimeLogger());
    vl.emplace_back(LifetimeLogger());

    return 0;
}