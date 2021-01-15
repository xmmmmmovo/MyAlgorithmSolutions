#include <algorithm>
#include <iostream>

using namespace std;

int L[100010];
int n, m;

bool check(double x) {
    int tm = 0;
    for (int i = 0; i < n; i++) {
        tm += L[i] / x;
    }
    // 因为后面输出的是l所以需要把答案包含进l里面
    return tm >= m;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &L[i]);
    }

    double l = 0, r = 1e9;
    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    printf("%.2lf", l);

    return 0;
}