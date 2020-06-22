package fundamentals

import ds.VisualAccumulator
import edu.princeton.cs.algs4.StdRandom

fun main() {
    val a = VisualAccumulator(10, 3.0)

    for (i in 0..5) {
        a.addDataValue(StdRandom.uniform())
    }

    println(a)
}