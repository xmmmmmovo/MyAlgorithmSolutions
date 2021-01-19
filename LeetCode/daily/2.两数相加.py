#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#
# Definition for singly-linked list.


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# @lc code=start


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode(None)
        tmp = head
        c, s = 0, 0
        while l1 or l2:
            v1, v2 = 0, 0
            if l1:
                v1 = l1.val
                l1 = l1.next
            if l2:
                v2 = l2.val
                l2 = l2.next
            s = v1 + v2 + c
            tmp.val = s % 10
            c = s // 10
            tmp.next = ListNode(None) if l1 or l2 or c != 0 else None
            tmp = tmp.next
        if c != 0:
            tmp.val = c
        return head

# @lc code=end
