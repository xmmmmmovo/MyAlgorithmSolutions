#include "include/ds/vector.hpp"
#include <algorithm>
#include <iostream>

using namespace ds;
using std::cout;
using std::endl;

int main() {
    vector<int> i(3, 100);

    cout << i << endl;
    i.append(1);
    cout << i << endl;

    return 0;
}
