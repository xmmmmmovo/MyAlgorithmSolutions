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
        s1, s2 = [], []
        while l1 or l2:
            s1.append(l1.val if l1 else 0)
            s2.append(l2.val if l2 else 0)

            l1 = l1.next
            l2 = l2.next

        print(s1)
        print(s2)

        n = ListNode(s1.pop() + s2.pop())
        tmp = n

        while s1:
            n.next = ListNode(s1.pop() + s2.pop())
            n = n.next

        while tmp:
            print(tmp)
            tmp = tmp.next

# @lc code=end
