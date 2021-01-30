/**
 * author: xmmmmmovo
 * generation time: 2021/01/29
 * filename: 906. 区间分组.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;
int       n;
PII       range[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &range[i].first, &range[i].second);

        
    return 0;
}