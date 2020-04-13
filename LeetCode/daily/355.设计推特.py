#
# @lc app=leetcode.cn id=355 lang=python3
#
# [355] 设计推特
#

# @lc code=start

from collections import defaultdict


class Data:
    pass


class LinkedList:
    class Node:
        def __init__(self, val):
            self.val = val
            self.next = None
    
    
    pass


class Twitter:

    def __init__(self):
        """
        Initialize your data structure here.
        """

    def postTweet(self, userId: int, tweetId: int) -> None:
        """
        Compose a new tweet.
        """

    def getNewsFeed(self, userId: int) -> List[int]:
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        """

    def follow(self, followerId: int, followeeId: int) -> None:
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        """

    def unfollow(self, followerId: int, followeeId: int) -> None:
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        """


# @lc code=end
