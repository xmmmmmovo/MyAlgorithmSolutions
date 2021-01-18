/**
 * author: xmmmmmovo
 * generation time: 2021/01/18
 * filename: 1208. 翻硬币.cpp
 * language & build version : C 11 & C++ 17
*/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string coins, res;
int cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> coins >> res;

    for (int i = 0; i < coins.size() - 1; i++) {
        if (coins[i] == res[i]) continue;
        else {
            coins[i] = coins[i] == 'o' ? '*' : 'o';
            coins[i + 1] = coins[i + 1] == 'o' ? '*' : 'o';
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
