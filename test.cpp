#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void coinChange(vector<int> &coins, int amount, int c_index, int count, int &ans) {
    cout << c_index << " " << ans << endl;
    if (amount == 0) {
        ans = min(ans, count);
        return;
    }
    if (c_index == coins.size())
        return;

    for (int k = amount / coins[ c_index ]; k >= 0 && k + count < ans; k--) {
        coinChange(coins, amount - k * coins[ c_index ], c_index + 1, count + k, ans);
    }
}

int coinChange(vector<int> &coins, int amount) {
    if (amount == 0)
        return 0;
    sort(coins.rbegin(), coins.rend());
    int ans = INT_MAX;
    coinChange(coins, amount, 0, 0, ans);
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    vector<int> v;
    v.emplace_back(1);
    coinChange(v, 2);
    return 0;
}