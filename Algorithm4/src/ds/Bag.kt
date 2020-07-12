package ds

class Bag<T> : Iterable<T> {
    private var first: Node<T>? = null
    private var n: Int = 0

    fun isEmpty(): Boolean = first == null

    fun size(): Int = n

    fun add(item: T) {
        val oi = first
        first = Node(
            item,
            oi
        )
        n++
    }

    override fun iterator(): Iterator<T> {
        return LinkedIterator(first)
    }
}