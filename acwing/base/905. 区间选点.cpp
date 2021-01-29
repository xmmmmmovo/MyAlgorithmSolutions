/**
 * author: xmmmmmovo
 * generation time: 2021/01/29
 * filename: 905. 区间选点.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;
int       n, res = 0;
PII       r[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &r[i].first, &r[i].second);
    }

    sort(r, r + n,
         [](auto const &a, auto const &b) { return a.second < b.second; });

    int ed = -2e9;
    for (auto const &range : r) {
        if (ed < range.first) {
            ed = range.second;
            res++;
        }
    }

    printf("%d", res);

    return 0;
}