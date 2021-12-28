/**
 * @file 476. Number Complement.cpp
 * @author xmmmmmovo
 * @brief
 * @version 0.1
 * @date 2021-12-27
 *
 * @copyright Copyright (c) 2021
 *
 */

class Solution {
  public:
    int findComplement(int num) {
        unsigned mask = ~0; // 1111 1111
        while (num & mask)
            mask <<= 1;
        return num ^ ~mask;
    }
};