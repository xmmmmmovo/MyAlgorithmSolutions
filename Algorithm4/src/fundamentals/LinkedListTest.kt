package fundamentals

import ds.LinkedList

data class N(val i: Int)

fun main() {
    val ll = LinkedList<Int>()
    for (i in 1..10)
        ll.add(i)
    println(ll)

    val numbers = mutableListOf<String>("aaaa")
    val mutableListIterator = numbers.listIterator()

    numbers.add(0, "1")
    numbers.add(1, "1")
    println(numbers)

//    mutableListIterator.add("two")
//    println(numbers)
//
//    println(mutableListIterator.next())
//    println(mutableListIterator.set("aa"))
////    mutableListIterator.remove()
////    println(mutableListIterator.next())
////    println(mutableListIterator.previous())
//    println(numbers)
//
//
//    var first: N? = N(1)
//    var second: N? = null
//
//    println("f$first,s$second")
//    second = first
//    println("f$first,s$second")
//    second = N(2)
//    println("f$first,s$second")
}
