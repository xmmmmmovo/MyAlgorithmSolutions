package fundamentals

import edu.princeton.cs.algs4.In
import java.io.File

fun <T : Comparable<T>> binarySearch(list: List<T>, key: T): Int {

    var lo = 0
    var hi = list.size - 1

    while (lo <= hi) {
        val mid = lo + (hi - lo) / 2
        if (key < list[mid]) {
            hi = mid - 1
        } else if (key > list[mid]) {
            lo = mid + 1
        } else {
            return mid
        }
    }

    return -1
}

fun main() {
    val list = File("data/tinyW.txt")
        .readText()
        .split("\n")
        .sorted()
        .filter { s: String ->
            s != ""
        }
        .map { s: String ->
            s.toInt()
        }

    for (i in In.readInts("data/tinyT.txt")) {
        println("key=${i} ans=${binarySearch(list, i)}")
    }
}
