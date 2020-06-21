package ds

import edu.princeton.cs.algs4.StdDraw
import edu.princeton.cs.algs4.StdRandom
import kotlin.math.min
import kotlin.math.sqrt

class Point2DMinDistanceCalculator constructor(
    private val N: Int = 0
) {
    private var minPointPair = Pair(Point2D(0.0, 0.0), Point2D(0.0, 0.0))
    private val list = Array(N) {
        Point2D(
            StdRandom.uniform(0.0, N.toDouble()),
            StdRandom.uniform(0.0, N.toDouble())
        )
    }

    init {
        StdDraw.setXscale(0.0, N.toDouble())
        StdDraw.setYscale(0.0, list.maxBy { it.y }!!.y + 0.3)
        StdDraw.setPenRadius(.005)
        StdDraw.setPenRadius(.01)
        StdDraw.setPenColor(StdDraw.RED)
    }


    private fun getDistance(lp: Point2D, rp: Point2D): Double {
        return sqrt(((rp.x - lp.x) * (rp.x - lp.x)) + ((rp.y - lp.y) * (rp.y - lp.y)))
    }

    fun getMinPointPair(): Pair<Point2D, Point2D> {
        return minPointPair
    }


    fun showPoints() {
        list.forEach {
            StdDraw.point(it.x, it.y)
        }
    }

    fun minDistanceForce(): Double {
        var minDistance = Double.MAX_VALUE

        if (N == 0) {
            return 0.0
        }

        for (lp in list) {
            for (rp in list) {
                if (lp != rp && getDistance(lp, rp) < minDistance) {
                    minDistance = getDistance(lp, rp)
                    minPointPair = Pair(lp, rp)
                }
            }
        }

        StdDraw.line(
            minPointPair.first.x, minPointPair.first.y,
            minPointPair.second.x, minPointPair.second.y
        )

        return minDistance
    }

    private fun divide(l: Int, r: Int): Double {
        if (r - l == 1) {
            return getDistance(list[r], list[l])
        } else if (r - l == 2) {
            return minOf(
                getDistance(list[l], list[l + 1]),
                getDistance(list[l], list[l + 2]),
                getDistance(list[l + 1], list[l + 2])
            )
        } else {

        }
        return 0.0
    }

    // TODO:分治法解最近点距离
    fun minDistanceDivide(): Double {
        if (N == 0) {
            return 0.0
        }
        list.sort()
        return divide(0, list.size - 1)
    }
}