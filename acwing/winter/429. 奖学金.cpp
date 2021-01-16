/**
 * author: xmmmmmovo
 * generation time: 2021/01/17
 * filename: 429. 奖学金.cpp
 * language & build version : C 11 & C++ 17
*/
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct student {
    int num;
    int yuwen;
    int shuxue;
    int yingyu;
    int sum;
    student(){}
    student(int nn, int yw, int sx, int yy) {
        num = nn;
        yuwen = yw;
        shuxue = sx;
        yingyu = yy;
        sum = yw + sx + yy;
    }
} stu;

stu students[310];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int yw, sx, yy;
        scanf("%d %d %d", &yw, &sx, &yy);
        students[i] = stu(i, yw, sx, yy);
    }

    sort(students + 1, students + n + 1, [](const stu &a, const stu &b) {
        if (a.sum != b.sum) return a.sum > b.sum;
        if (a.yuwen != b.yuwen) return a.yuwen > b.yuwen;
        return a.num < b.num;
    });

    for (int i = 1; i <= 5; i++) printf("%d %d\n", students[i].num, students[i].sum);


    return 0;
}