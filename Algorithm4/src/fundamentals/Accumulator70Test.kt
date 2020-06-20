package fundamentals

import ds.Accumulator
import edu.princeton.cs.algs4.StdRandom

fun main() {
    val a = Accumulator()

    for (i in 0..1000) {
        a.addDataValue(StdRandom.uniform())
    }

    println(a)
}