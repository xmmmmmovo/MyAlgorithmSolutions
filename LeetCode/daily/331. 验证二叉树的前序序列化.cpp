/**
 * author: xmmmmmovo
 * generation time: 2021/03/12
 * filename: 331. 验证二叉树的前序序列化.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isValidSerialization(string preorder) {
        int res = 1;

        for (int i = 0; i < preorder.size(); i++) {
            if (!res)
                return false;

            if (preorder[i] == ',') {
                continue;
            } else if (preorder[i] == '#') {
                res--;
            } else {
                while (i < preorder.size() &&
                       preorder[i + 1] != ',') {
                    i++;
                }
                res++;
            }
        }
        return !res;
    }
};