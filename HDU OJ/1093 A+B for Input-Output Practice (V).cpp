/**
 * author: xmmmmmovo
 * generation time: 2019/05/20
 * filename: 1093 A+B for Input-Output Practice (V).cpp
 * language & build version : C++ 11
 */
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[]) {
    int n;

    scanf("%d", &n);

    while (n--) {
        int k;
        ll  tmp, sum = 0;

        scanf("%d", &k);

        while (k--) {
            scanf("%lld", &tmp);
            sum += tmp;
        }

        printf("%lld\n", sum);
    }

    return 0;
}