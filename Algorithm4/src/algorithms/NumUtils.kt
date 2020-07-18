package algorithms

import ds.LinkedList

/**
 * 蛮力法求四数之和
 * */
fun fourSumForce(list: List<Int>, num: Int): Int {
    var cnt = 0

    for (a in list.indices)
        for (b in a until list.size)
            for (c in b until list.size)
                for (d in c until list.size)
                    if (list[a] + list[b] + list[c] + list[d] == num) {
                        cnt++
                    }
    return cnt
}

/**
 * 二分求三数之和
 * */
fun threeSumBinaryFast(list: List<Int>): List<List<Int>> {
    var res = LinkedList<List<Int>>()

    val sl = list.sorted()

    for (item in sl) {

    }

    return res
}

/**
 * 双指针求三数之和
 * */
fun threeSumDoublePointFast(list: List<Int>): List<List<Int>> {
    var res = LinkedList<List<Int>>()

    val sl = list.sorted()

    for (item in sl) {

    }

    return res
}