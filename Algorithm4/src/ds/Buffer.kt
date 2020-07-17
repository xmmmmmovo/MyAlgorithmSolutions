package ds

class Buffer {
    private val ls = Stack<Char>()
    private val rs = Stack<Char>()

    /**
     * 光标处插入
     * */
    fun insert(c: Char) {
        ls.push(c)
    }

    /**
     * 光标左边删除
     * */
    fun delete(): Char =
        if (ls.size() == 0) throw NoSuchElementException("无法删除")
        else ls.pop()

    /**
     * 光标左移
     * */
    fun left(k: Int) {
        if (k > ls.size()) throw IllegalArgumentException("无法到达")
        for (i in 1..k) {
            rs.push(ls.pop())
        }
    }

    /**
     * 光标右移
     * */
    fun right(k: Int) {
        if (k > rs.size()) throw IllegalArgumentException("无法到达")
        for (i in 1..k) {
            ls.push(rs.pop())
        }
    }

    /**
     * 返回buffer大小
     * */
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