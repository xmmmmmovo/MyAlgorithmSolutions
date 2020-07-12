package ds

internal class LinkedIterator<T>(
    private var current: Node<T>?
) : Iterator<T> {

    override fun hasNext(): Boolean {
        return current != null
    }

    fun remove() {
        throw UnsupportedOperationException()
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