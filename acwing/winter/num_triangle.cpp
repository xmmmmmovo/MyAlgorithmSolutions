#include <algorithm>
#include <iostream>

using namespace std;

int q[510][510];

int main() {
    int f;
    scanf("%d", &f);

    for (size_t i = 0; i < f; i++) {
        for (size_t j = 0; j < i; j++) {
            scanf("%d", &q[i][j]);
        }
    }


    return 0;
}