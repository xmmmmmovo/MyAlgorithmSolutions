--
-- @lc app=leetcode.cn id=175 lang=mysql
--
-- [175] 组合两个表
--

-- @lc code=start
-- # Write your MySQL query statement below

SELECT FirstName, LastName, City, State
FROM Person LEFT JOIN (
    SELECT DISTINCT PersonId, City, State FROM Address
) B
ON Person.PersonId = B.PersonId;

-- @lc code=end

