package fundamentals

data class tt(val string: String = "")

fun main() {
    var t = tt("11")

    var tmp = tt("22")
    println(t.string.let {
        t = tmp
    })

    println(tmp)
}