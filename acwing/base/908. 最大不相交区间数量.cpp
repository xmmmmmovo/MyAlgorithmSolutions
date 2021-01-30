/**
 * author: xmmmmmovo
 * generation time: 2021/01/29
 * filename: 908. 最大不相交区间数量.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n;
PII range[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &range[i].first, &range[i].second);
    }

    sort(range, range + n,
         [](auto const &a, auto const &b) { return a.second < b.second; });

    int res = 0, ed = -2e9;
    for (auto const &r : range) {
        if (ed < r.first) {
            ed = r.second;
            res++;
        }
    }
    printf("%d", res);

    return 0;
}