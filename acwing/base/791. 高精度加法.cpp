/**
 * author: xmmmmmovo
 * generation time: 2021/01/13
 * filename: 791. 高精度加法.cpp
 * language & build version : C 11 & C++ 17
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> C;

    if (A.size() < B.size()) return add(B, A);

    int t = 0;// 表示进位

    for (int i = 0; i < A.size(); i++) {
        t += A[i];
        if (i < B.size()) t += B[i];

        C.emplace_back(t % 10);
        t /= 10;
    }
    if (t) C.emplace_back(1);
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

    auto c = add(A, B);

    for (int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);

    return 0;
}