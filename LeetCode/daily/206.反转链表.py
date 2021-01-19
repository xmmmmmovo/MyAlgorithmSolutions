#
# @lc app=leetcode.cn id=206 lang=python3
#
# [206] 反转链表
#

# Definition for singly-linked list.


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# @lc code=start


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        cur = head
        pre = None

        while cur is not None:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp

        return pre

# @lc code=end
