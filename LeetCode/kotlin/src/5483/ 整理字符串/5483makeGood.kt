package `5483`

import java.util.*
import kotlin.test.assertEquals

class Solution {
    fun makeGood(s: String): String {
        val sb = StringBuilder()
        val st = LinkedList<Char>()

        s.forEach { c: Char ->
            when {
                c.isUpperCase() && st.isNotEmpty() && st.peek() == c.toLowerCase() -> {
                    st.pop()
                }
                c.isLowerCase() && st.isNotEmpty() && st.peek() == c.toUpperCase() -> {
                    st.pop()
                }
                else -> {
                    st.push(c)
                }
            }
        }
        
        while (st.isNotEmpty()) {
            sb.append(st.removeLast())
        }

        return sb.toString()
    }
}

fun main() {
    assertEquals("leetcode", Solution().makeGood("leEeetcode"))
    assertEquals("", Solution().makeGood("abBAcC"))
    assertEquals("", Solution().makeGood("Pp"))
    assertEquals("s", Solution().makeGood("s"))
}