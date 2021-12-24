/**
 * @file 1002 A+B for Polynomials.cpp
 * @author xmmmmmovo
 * @brief
 * @version 0.1
 * @date 2021-12-19
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

int n, m;

float N[1005];

int main() {
    int   e;
    float c;
    int   cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %f", &e, &c);
        N[e] += c;
        cnt++;
    }
    // printf("%d", cnt);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %f", &e, &c);
        if (N[e] == 0)
            cnt++;
        N[e] += c;
        if (N[e] == 0)
            cnt--;
    }

    printf("%d", cnt);
    for (int i = 1004; i >= 0; i--) {
        if (N[i] == 0)
            continue;
        printf(" %d %.1f", i, N[i]);
    }

    return 0;
}