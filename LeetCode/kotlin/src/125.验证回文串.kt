/**
分享个字母大小写转换的方法：

统一转成大写：ch & 0b11011111 简写：ch & 0xDF
统一转成小写：ch | 0b00100000 简写：ch | 0x20
比较的时候注意加上小括号哦，因为位运算优先级比较低。

使用示例：

if((s.charAt(i ++) & 0xDF) != (s.charAt(j --) & 0xDF)) return false;
 * */

class Solution {
    fun isPalindrome(s: String): Boolean {
        if (s.isEmpty())
            return true

        val ss = s.filter { c: Char ->
            c.isLetterOrDigit()
        }.run {
            toLowerCase()
        }

        var l = 0
        var r = ss.length - 1

        while (l < r) {
            if (ss[l].toLowerCase() != ss[r].toLowerCase()) {
                return false
            }

            l++
            r--
        }

        return true
    }
}

fun main() {
    println(Solution().isPalindrome("A man, a plan, a canal: Panama"))
    println(Solution().isPalindrome("race a car"))
}