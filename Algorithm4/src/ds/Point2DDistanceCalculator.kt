package ds

import edu.princeton.cs.algs4.StdRandom

class Point2DDistanceCalculator constructor(
    N: Int = 0
) {
    private val list = Array(N) {
        Point2D(
            StdRandom.uniform(0.0, N.toDouble()),
            StdRandom.uniform(0.0, N.toDouble())
        )
    }.sorted()

    init {

    }

    fun showPoints() {
    }
}