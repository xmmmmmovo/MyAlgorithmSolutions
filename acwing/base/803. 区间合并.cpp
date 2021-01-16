/**
 * author: xmmmmmovo
 * generation time: 2021/01/16
 * filename: 803. 区间合并.cpp
 * language & build version : C 11 & C++ 17
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

typedef pair<int, int> PII;
int n;
int l, r;
vector<PII> segs;

void merge() {
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for (auto const &seg : segs) {
        if (ed < seg.first) {
            if (st != -2e9) res.emplace_back(st, ed);
            st = seg.first, ed = seg.second;
        } else
            ed = max(ed, seg.second);
    }
    if (st != -2e9) res.emplace_back(st, ed);
    segs = res;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l, &r);
        segs.emplace_back(l, r);
    }

    merge();

    printf("%d", segs.size());
    return 0;
}