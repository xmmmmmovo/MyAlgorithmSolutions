package fundamentals

import ds.Stack

fun main() {
    val s = Stack<String>()

    for (i in 1..10) {
        s.push(i.toString())
        println(s)
    }

    println(s.peek())

    s.pop()

    println(s)


}