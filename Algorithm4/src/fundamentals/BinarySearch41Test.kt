package fundamentals

import edu.princeton.cs.algs4.In
import utils.binarySearch
import utils.containsInList
import java.io.File

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
        println("contains=${containsInList(list, i)}")
        println("key=${i} ans=${binarySearch(list, i)}")
    }
}
