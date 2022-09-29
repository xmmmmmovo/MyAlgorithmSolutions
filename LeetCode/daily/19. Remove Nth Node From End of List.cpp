/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *forenode = head, *backnode = head, *ffnode = NULL;
        for (int i = 0; i < n; i++) {
            backnode = backnode->next;
        }
        if (!backnode)
            return head->next;
        while (backnode) {
            ffnode   = forenode;
            forenode = forenode->next;
            backnode = backnode->next;
        }
        ffnode->next = forenode->next;
        return head;
    }
};