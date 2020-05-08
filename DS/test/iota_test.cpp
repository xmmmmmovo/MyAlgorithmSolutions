//
// Created by xmmmmmovo on 2020/5/8.
//
#include "../include/algorithm/functional.hpp"
#include "../include/ds/itoa.hpp"
#include <iostream>

using namespace ds;
using std::cout;
using std::endl;

bool is_prime(const size_t n) {
    if (n < 2) return false;
    for (size_t i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    for (const auto i : filter(itoa, is_prime)) {
        cout << i << endl;
    }

    return 0;
}