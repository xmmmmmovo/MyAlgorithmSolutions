#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

int t;

int n;

void solve() {
    scanf("%d", &n);
    int tmp       = n - 4;
    int single    = tmp / 3;
    int remainder = tmp % 3;
    int l1 = single, l2 = 1, l3 = single * 2;

    if (remainder == 2) {
        l1 += 1;
        l3 += 1;
    } else if (remainder == 1) {
        l3 += 1;
    }

    printf("%d\n", min(l1 - l2, l3 - l2));
    return;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        solve();
    }

    return 0;
}