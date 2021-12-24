#include <cmath>
#include <cstdio>
#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;

int n, x;
int a[N];

int main() {
    scanf("%d %d", &n, &x);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // x已经给你了
    if (n == 1) {
        printf("0");
    } else if (n == 2) {
        printf("%d", abs(abs(a[1] - a[0]) - x));
    } else {
        
    }

    return 0;
}