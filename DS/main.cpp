#include <iostream>
#include <algorithm>
#include "include/ds/vector.hpp"

using namespace ds;
using std::cout;
using std::endl;

int main() {
    vector<int> i(3, 100);

    i[2] = 1;
    i[0] = 1;

    cout << i << endl;
    cout << i[-1] << endl;

    return 0;
}
