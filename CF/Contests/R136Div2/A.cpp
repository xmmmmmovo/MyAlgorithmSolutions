#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

int n;
int nn, mm;

int dir[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1},
                 {2, 1},   {1, 2},   {-1, 2}, {-2, 1}};

void solve() {
    for (int i = 1; i <= nn; i++) {
        for (int j = 1; j <= mm; j++) {
            bool res = true;
            for (int k = 0; k < 8; k++) {
                int d1 = i + dir[k][0];
                int d2 = j + dir[k][1];

                if (d1 >= 1 && d2 >= 1 && d1 <= nn && d2 <= mm) {
                    res = false;
                    break;
                }
            }
            if (res) {
                printf("%d %d\n", i, j);
                return;
            }
        }
    }

    printf("%d %d\n", nn, mm);
    return;
}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &nn, &mm);
        solve();
    }

    return 0;
}