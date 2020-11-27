package `5496`

class Solution {
    fun maxCoins(piles: IntArray): Int {
        piles.sort()
        var l = 0
        var r = piles.lastIndex - 1
        var res = 0
        while (l < r) {
            res += piles[r]
            r -= 2
            l++
        }
        return res
    }
}