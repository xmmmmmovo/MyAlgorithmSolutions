/**
 * author: xmmmmmovo
 * generation time: 2021/01/20
 * filename: 1341. 十三号星期五.cpp
 * language & build version : C 11 & C++ 17
 */
#include <iostream>

using namespace std;

int  n, wc[7];
bool month[] = {1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1};

int week(int y, int m, int d) {
    if (m < 3) {
        m += 12;
        y--;
    }
    return ((d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7);
}

int main() {
    scanf("%d", &n);

    for (int i = 1900; i < 1900 + n; i++)
        for (int j = 1; j <= 12; j++) {
            // int m = 0;
            // if (j == 2)
            //     m = (((i % 4) && !(i % 100)) || (i % 400)) ? 29 : 28;
            // else if (month[j])
            //     m = 31;
            // else
            //     m = 30;
            // for (int k = 1; k <= m; k++)
            //     wc[week(i, j, k) - 1]++;
            wc[week(i, j, 13)]++;
        }
    printf("%d ", wc[6]);
    for (int i = 0; i < 6; i++)
        printf("%d ", wc[i]);

    return 0;
}