/**
 * author: xmmmmmovo
 * generation time: 2021/01/18
 * filename: 794. 高精度除法.cpp
 * language & build version : C 11 & C++ 17
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// A / b = c ''''' 2
tuple<vector<int>, int> div(vector<int> &A, int b) {

    vector<int> c;
    int r = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        c.push_back(r / b);
        r %= b;
    }
    reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return make_tuple(c, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    int b;

    cin >> a >> b;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    auto [c, r] = div(A, b);

    for (int i = c.size() - 1; i >= 0; i--)
        printf("%d", c[i]);

    printf("\n%d\n", r);

    return 0;
}