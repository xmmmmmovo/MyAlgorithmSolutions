#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <unordered_map>

using namespace std;
using ll  = long long;
using PII = pair<int, int>;

const int N = 1e5 + 10;

int n;
PII m[N];

int main() {
    int res = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m[i].first, &m[i].second);
    }

    sort(m, m + n, [](PII a, PII b) { return a.first < b.first; });

    for (auto &&p : m) {
        if (res == 0) {
            res += p.first;
            res += p.second;
            continue;
        }
        res += p.first - res <= 0 ? 0 : p.first - res;
        res += p.second;
    }

    printf("%d", res);
    return 0;
}