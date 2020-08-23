package `5495`

import java.util.*
import kotlin.test.assertEquals

class Solution {
    fun mostVisited(n: Int, rounds: IntArray): List<Int> {
        val res = LinkedList<Int>()

        

        return 0
    }
}

fun main() {
    assertEquals(listOf(1, 2), Solution().mostVisited(n = 4, rounds = intArrayOf(1, 3, 1, 2)))
    assertEquals(listOf(2), Solution().mostVisited(n = 2, rounds = intArrayOf(2, 1, 2, 1, 2, 1, 2, 1, 2)))
    assertEquals(listOf(1, 2, 3, 4, 5, 6, 7), Solution().mostVisited(n = 7, rounds = intArrayOf(1, 3, 5, 7)))
}