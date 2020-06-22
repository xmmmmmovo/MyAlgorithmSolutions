package fundamentals

import ds.Date
import ds.Transaction

fun main() {
    println(Date("2002/1/12"))
    println(Date(1, 2, 3))
    println(Transaction("T 2002/5/22 11.99"))
}