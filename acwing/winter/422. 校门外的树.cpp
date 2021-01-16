/**
 * author: xmmmmmovo
 * generation time: 2021/01/16
 * filename: 422. 校门外的树.cpp
 * language & build version : C 11 & C++ 17
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

int l, m, st, ed;

vector<PII> merge(vector<PII> &segs) {
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int st = -1, ed = -1;
    for (auto const &seg : segs) {
        if (ed < seg.first) {
            if (st != -1) res.emplace_back(st, ed);
            st = seg.first, ed = seg.second;
        } else
            ed = max(ed, seg.second);
    }

    if (st != -1) res.emplace_back(st, ed);

    return res;
}

int count(vector<PII> &segs) {
    int sum = 0;
    for (auto const &seg : segs) sum += (seg.second - seg.first);
    return sum;
}

int main() {
    scanf("%d %d", &l, &m);
    vector<PII> segs(m, {0, 0});

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &st, &ed);
        segs[i] = make_pair(st, ed);
    }
    segs = merge(segs);
    // 因为两端都有树所以要-size() 有因为末端有树所以+1
    printf("%d", l - count(segs) - segs.size() + 1);

    return 0;
}