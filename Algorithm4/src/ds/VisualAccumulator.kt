package ds

import edu.princeton.cs.algs4.StdDraw

class VisualAccumulator constructor(
    val xMax: Int = 100,
    val yMax: Double = 100.0
) {
    var times: Int = 0
    var total: Double = 0.0

    init {
        StdDraw.setXscale(0.0, xMax.toDouble())
        StdDraw.setYscale(0.0, yMax)
        StdDraw.setPenRadius(.005)
    }

    fun <T : Number> addDataValue(value: T) {
        total += value.toDouble()
        times++

        StdDraw.setPenColor(StdDraw.DARK_GRAY)
        StdDraw.point(times.toDouble(), value.toDouble())
        StdDraw.setPenColor(StdDraw.RED)
        StdDraw.point(times.toDouble(), mean())
    }

    fun mean(): Double = total / times

    override fun toString(): String {
        return "Mean ($times times, ${String.format("%.2f", total)} values): " +
                "${String.format("%7.5f", mean())}"
    }
}