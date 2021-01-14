/**
 * author: xmmmmmovo
 * generation time: 2021/01/14
 * filename: 792. 高精度减法.cpp
 * language & build version : C 11 & C++ 17
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 判断A是否大于B
bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() >= B.size();
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.emplace_back((t + 10) % 10);
        if (t < 0) t = 1;
        else
            t = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;

    vector<int> A, B;

    cin >> a >> b;

    for (auto c = a.rbegin(); c != a.rend(); c++) A.emplace_back(*c - '0');
    for (auto c = b.rbegin(); c != b.rend(); c++) B.emplace_back(*c - '0');

    if (cmp(A, B)) {
        auto c = sub(A, B);
        for (int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);
    } else {
        auto c = sub(B, A);
        printf("-");
        for (int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);
    }

    return 0;
}