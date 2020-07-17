package ds

class Bag<T> : Iterable<T> {
    private var first: Node<T>? = null
    private var n: Int = 0

    /**
     * 是否为空
     * */
    fun isEmpty(): Boolean = first == null

    /**
     * 返回长度
     * */
    fun size(): Int = n

    /**
     * 添加元素
     * */
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

    private data class Node<T>(
        val item: T,
        var next: Node<T>? = null
    )

    private class LinkedIterator<T>(
        private var current: Node<T>?
    ) : Iterator<T> {

        override fun hasNext(): Boolean {
            return current != null
        }

        override fun next(): T {
            if (!hasNext()) {
                throw NoSuchElementException()
            }
            val item = current?.item
            current = current?.next
            return item!!
        }
    }
}