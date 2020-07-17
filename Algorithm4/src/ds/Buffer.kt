package ds

class Buffer {
    private val ls = Stack<Char>()
    private val rs = Stack<Char>()

    fun insert(c: Char) {
        ls.push(c)
    }

    fun delete(): Char =
        if (ls.size() == 0) throw NoSuchElementException("无法删除")
        else ls.pop()

    fun left(k: Int) {
        if (k > ls.size()) throw IllegalArgumentException("无法到达")
        for (i in 1..k) {
            rs.push(ls.pop())
        }
    }

    fun right(k: Int) {
        if (k > rs.size()) throw IllegalArgumentException("无法到达")
        for (i in 1..k) {
            ls.push(rs.pop())
        }
    }

    val size: Int
        get() = ls.size() + rs.size()

    override fun toString(): String {
        return StringBuilder().also {
            it.append(ls)
            it.reverse()
            it.append(" | ")
            it.append(rs)
        }.toString()
    }
}