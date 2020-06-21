package ds

import kotlin.reflect.typeOf

class Rational constructor(
    private var numerator: Long,
    private var denominator: Long = 1L
) : Comparable<Rational> {
    init {
        if (denominator == 0L) {
            throw IllegalAccessError("分母不能为0!")
        }
    }

//    private fun simplify() {
//        val g =
//    }

    public operator fun plus(other: Rational): Rational {
        return Rational(0, 0)
    }

    public operator fun minus(other: Rational): Rational {
        return Rational(0, 0)
    }

    public operator fun times(other: Rational): Rational {
        return Rational(0, 0)
    }

    public operator fun div(other: Rational): Rational {
        return Rational(0, 0)
    }

    override fun equals(other: Any?): Boolean {
        if (other == null) return false
        if (this::class != other::class) return false
        return this.compareTo(other as Rational) == 0
    }

    override fun toString(): String {
        if (denominator == 1L) {
            return "$numerator"
        }
        return "$numerator/$denominator"
    }

    override fun compareTo(other: Rational): Int {
        return 0
    }
}