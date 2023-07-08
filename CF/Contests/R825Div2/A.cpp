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

int  n;
int  a[110], b[110];
void solve() {
    scanf("%d", &n);
    int a0 = 0, b0 = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 0)
            a0++;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        if (b[i] == 0)
            b0++;
    }

    if (a0 == b0) {
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                printf("1\n");
                return;
            }
        }
        printf("0\n");
        return;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cnt++;
        }
    }
    int res = abs(a0 - b0);
    if (cnt > res)
        printf("%d\n", res + 1);
    else
        printf("%d\n", res);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        solve();
    }

    return 0;
}