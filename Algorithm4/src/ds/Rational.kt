package ds

import utils.qgcd
import kotlin.reflect.typeOf

class Rational constructor(
    private var numerator: Long,
    private var denominator: Long = 1L
) : Comparable<Rational> {
    init {
        if (denominator == 0L) {
            throw IllegalAccessError("分母不能为0!")
        }

        simplify()
    }

    fun numerator(): Long {
        return numerator
    }

    fun denominator(): Long {
        return denominator
    }

    private fun simplify() {
        val g = qgcd(numerator, denominator)
        numerator /= g
        denominator /= g
        if (denominator < 0) {
            denominator = -denominator
            numerator = -numerator
        }
    }

    public operator fun plus(other: Rational): Rational {
        if (this.numerator == 0L) return other
        if (other.numerator == 0L) return this
        val g = qgcd(this.denominator, other.denominator)
        return Rational(
            this.numerator * (other.denominator / g) + other.numerator * (this.denominator / g),
            this.denominator * (other.denominator / g)
        )
    }

    public operator fun minus(other: Rational): Rational {
        if (this.numerator == 0L) return other
        if (other.numerator == 0L) return this

        val g = qgcd(this.denominator, other.denominator)
        return Rational(
            this.numerator * (other.denominator / g) - other.numerator * (this.denominator / g),
            this.denominator * (other.denominator / g)
        )
    }

    public operator fun times(other: Rational): Rational {
        return Rational(
            this.numerator * other.numerator,
            this.denominator * other.denominator
        )
    }

    public operator fun div(other: Rational): Rational {
        return Rational(
            this.numerator * other.denominator,
            this.denominator * other.numerator
        )
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
        // 除法判断大小于
        val num = this.numerator * other.denominator
        val den = this.denominator * other.numerator
        if (num > den)
        // 说明分子大 当前数大
            return 1
        if (num < den)
            return -1
        return 0
    }
}