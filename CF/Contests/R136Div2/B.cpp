#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int t;
int n;
int arr[110], d[110];

void solve() {
    arr[1] = d[1];
    for (int i = 2; i <= n; i++) {
        int ap = d[i] + arr[i - 1];
        int an = -d[i] + arr[i - 1];
        if (ap < 0) {
            arr[i] = an;
            continue;
        }
        if (an < 0) {
            arr[i] = ap;
            continue;
        }
        if (ap != an) {
            printf("-1\n");
            return;
        }
        arr[i] = ap;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &d[i]);
        }
        solve();
    }

    return 0;
}