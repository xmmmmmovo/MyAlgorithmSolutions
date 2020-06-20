package fundamentals

import ds.Counter
import edu.princeton.cs.algs4.StdRandom
import kotlin.math.abs

fun main() {
    var times = 10000
    val heads = Counter("heads")
    val tails = Counter("tails")

    while (times-- != 0) {
        if (StdRandom.bernoulli(0.5)) {
            heads.increment()
        } else {
            tails.increment()
        }
    }

    println(heads)
    println(tails)
    println("delta: ${abs(heads.tally() - tails.tally())}")
}