package fundamentals

import edu.princeton.cs.algs4.StdDraw
import kotlin.math.log2

fun main() {
    val N = 100
    StdDraw.setXscale(0.0, N.toDouble())
    StdDraw.setYscale(0.0, (N * N).toDouble())

    for (i in 1..N) {
        StdDraw.point(i.toDouble(), i.toDouble())
        StdDraw.point(i.toDouble(), (i * i).toDouble())
        StdDraw.point(i.toDouble(), i * log2(i.toDouble()))
    }
}