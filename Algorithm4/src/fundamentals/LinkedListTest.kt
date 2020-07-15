package fundamentals

import ds.LinkedList

data class N(val i: Int)

fun main() {
//    val ll = LinkedList<Int>()
    val numbers = mutableListOf<String>("aaa", "bbb")
    val mutableListIterator = numbers.listIterator()

    mutableListIterator.add("two")
    println(numbers)

    println(mutableListIterator.next())
    mutableListIterator.remove()
    println(mutableListIterator.next())
//    println(mutableListIterator.previous())
    println(numbers)


    var first: N? = N(1)
    var second: N? = null

    println("f$first,s$second")
    second = first
    println("f$first,s$second")
    second = N(2)
    println("f$first,s$second")
}
