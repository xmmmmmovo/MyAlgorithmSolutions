/**
 * author: xmmmmmovo
 * generation time: 2021/02/26
 * filename: 剑指 Offer 06. 从尾到头打印链表.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int       val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    vector<int> reversePrint(ListNode *head) {
        vector<int> res;

        while (head != NULL) {
            res.emplace_back(head->val);
            head = head->next;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};