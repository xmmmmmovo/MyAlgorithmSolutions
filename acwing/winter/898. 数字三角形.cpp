#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;
int f[510][510];


int main() {
    scanf("%d", &n);

    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= i; j++) {
            scanf("%d", &f[i][j]);
        }
    }

    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
        }
    }

    printf("%d", f[1][1]);

    return 0;
}