package fundamentals

data class tt(var string: String = "")

fun  test1() {
    var t = tt("11")

    var tmp = tt("22")
    println(t.string.let {
        t = tmp
    })

    println(tmp)

    for (i in 1..10)
        println(i)
}

fun main() {
    val a = listOf<String>("111", "222")
    val b = listOf<String>()
    println(b.all { a.contains(it) })
}