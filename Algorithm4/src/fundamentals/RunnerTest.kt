package fundamentals

data class tt(val string: String = "")

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
    var x = 0
    for (i in 0..3) {
        x++
        println(x)
    }
}