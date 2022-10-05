#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

const int N = 1e7 + 10;

int t;
int n;
int a[N];

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    if (n == 1) {
        printf("0\n");
        return;
    }

    // whether sorted ?
    sort(a, a + n);

    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int div = a[i] / a[0];
        int rem = a[i] % a[0];

        if (div >= 2) {
            int dd = div / 2;
            int rr = div % 2;
            rem += dd + rr * a[0];
            cnt += dd;

            while (rem / a[0] >= 2) {
                int div = rem / a[0];
                int dd  = div / 2;
                int rr  = div % 2;
                rem     = dd + rem % a[0] + rr * a[0];
                cnt += dd;
            }
        }
    }
    printf("%d\n", cnt);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        solve();
    }

    return 0;
}