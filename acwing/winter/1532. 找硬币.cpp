/**
 * author: xmmmmmovo
 * generation time: 2021/01/19
 * filename: 1532. 找硬币.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int coins[ N ];

// int main() {
//     scanf("%d %d", &n, &m);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &coins[ i ]);
//     unordered_map<int, int> map;

//     int res = 1001;
//     for (int i = 0; i < n; i++) {
//         if (map.count(m - coins[ i ]) != 0)
//             res = min(coins[ map[ m - coins[ i ] ] ], res);
//         map[ coins[ i ] ] = i;
//     }
//     if (res == 1001)
//         printf("No Solution");
//     else
//         printf("%d %d", res, coins[ map[ m - res ] ]);

//     return 0;
// }

bool check(int i, int j) {}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[ i ]);

    sort(coins, coins + n);
    for (int i = 0, j = n - 1; i < j;) {
        if (coins[ i ] + coins[ j ] == m) {
            printf("%d %d", coins[ i ], coins[ j ]);
            return 0;
        } else if (coins[ i ] + coins[ j ] > m)
            j--;
        else
            i++;
    }
    printf("No Solution");
    return 0;
}