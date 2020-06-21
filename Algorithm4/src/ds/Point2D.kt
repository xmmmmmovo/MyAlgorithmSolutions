package ds

import edu.princeton.cs.algs4.StdRandom

class Point2D constructor(
    val x: Double = 0.0,
    val y: Double = 0.0
) : Comparable<Point2D> {

    override fun compareTo(other: Point2D): Int {
        if (this.x < other.x || this.y < other.y) {
            return -1
        }
        if (this.x > other.x || this.y > other.y) {
            return 1
        }
        return 0
    }

    override fun toString(): String {
        return "x=$x, y=$y"
    }
}