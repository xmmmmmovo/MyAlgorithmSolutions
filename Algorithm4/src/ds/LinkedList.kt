package ds

import kotlin.NoSuchElementException

/**
 *
 * */
class LinkedList<T> : MutableList<T> {
    private var first: Node<T>? = null
    private var last: Node<T>? = null
    private var _size: Int = 0

    override fun add(element: T): Boolean {
        linkedLast(element)
        return true
    }

    override fun add(index: Int, element: T) {
        checkPositionIndex(index, size)
        if (index == _size) {
            linkedLast(element)
        } else {
            linkedBefore(element, getNode(index))
        }
    }

    override fun addAll(index: Int, elements: Collection<T>): Boolean {
        TODO("Not yet implemented")
    }

    override fun addAll(elements: Collection<T>): Boolean {
        TODO("Not yet implemented")
    }

    override fun clear() {
        TODO("Not yet implemented")
    }

    override fun remove(element: T): Boolean {
        TODO("Not yet implemented")
    }

    override fun removeAll(elements: Collection<T>): Boolean {
        TODO("Not yet implemented")
    }

    override fun removeAt(index: Int): T {
        TODO("Not yet implemented")
    }

    override fun retainAll(elements: Collection<T>): Boolean {
        TODO("Not yet implemented")
    }

    override fun set(index: Int, element: T): T {
        TODO("Not yet implemented")
    }

    override fun contains(element: T): Boolean {
        return indexOf(element) != -1
    }

    override fun containsAll(elements: Collection<T>): Boolean {
        return elements.all {
            contains(it)
        }
    }

    override fun get(index: Int): T {
        return getNode(index).item ?: throw NoSuchElementException()
    }

    override fun indexOf(element: T): Int {
        var index = 0
        this.forEach {
            if (it == element) {
                return index
            }
            index++
        }
        return -1
    }

    /**
     * 链表是否为空
     * */
    override fun isEmpty(): Boolean = _size == 0

    /**
     * 可以查到的最后一个元素
     * */
    override fun lastIndexOf(element: T): Int {
        TODO("Not yet implemented")
    }

    /**
     * 返回迭代器
     * */
    override fun iterator(): MutableIterator<T> {
        return LinkedIterator(0, first)
    }

    /**
     * 返回列表迭代器
     * */
    override fun listIterator(): MutableListIterator<T> {
        return LinkedListIterator(0, first)
    }


    /**
     * 返回从某个index开始的迭代器
     * */
    override fun listIterator(index: Int): MutableListIterator<T> {
        return LinkedListIterator(index, getNode(index))
    }

    /**
     * 返回子列表
     * */
    override fun subList(fromIndex: Int, toIndex: Int): MutableList<T> {
        TODO("Not yet implemented")
    }

    override val size: Int
        get() = _size

    fun getFirst(): T {
        return first?.item ?: throw NoSuchElementException()
    }

    fun getLast(): T {
        return last?.item ?: throw NoSuchElementException()
    }

    fun reverse() {
    }

    fun addFirst(element: T) {
        linkedFirst(element)
    }

    fun addLast(element: T) {
        linkedLast(element)
    }

    fun removeFirst(): T {
        if (first == null) throw NoSuchElementException()
        return unlinkFirst()
    }

    fun removeLast(): T {
        if (last == null) throw NoSuchElementException()
        return unlinkLast()
    }

    /**
     * 获取某个节点
     * 判断1/2的size然后从左往右或者从右往左查找
     * */
    private fun getNode(index: Int): Node<T> = if (index < (_size shr 1)) {
        var node = first
        for (i in 0 until index) {
            node = node?.next
        }
        node!!
    } else {
        var node = last
        for (i in _size - 2 downTo index) {
            node = node?.prev
        }
        node!!
    }

    /**
     * 连接到首节点
     * */
    private fun linkedFirst(item: T) {
        val f = first
        val nNode = Node(item, null, f)
        first = nNode
        if (f == null) {
            last = nNode
        } else {
            f.prev = nNode
        }
        _size++
    }

    /**
     * 连接到某节点前面
     * */
    private fun linkedBefore(item: T, node: Node<T>) {
        val prev = node.prev
        val nNode = Node(item, prev, node)
        node.prev = nNode
        if (prev == null) {
            first = nNode
        } else {
            prev.next = nNode
        }
        _size++
    }

    /**
     * 连接到last
     * */
    private fun linkedLast(item: T) {
        val l = last
        val nNode = Node(item, l, null)
        last = nNode

        if (l == null) {
            first = last
        } else {
            l.next = nNode
        }
        _size++
    }

    private fun unlinkFirst(): T {
    }

    private fun unlinkLast(): T {
    }

    private fun unlinked(node: Node<T>): T {
        val np = node.prev
        val nn = node.next
        val ne = node.item

        if (np == null) {
            first = nn
        } else {
            np.next = nn
            node.prev = null
        }

        if (nn == null) {
            last = np
        } else {
            nn.prev = np
            node.next = null
        }

        node.item = null
        _size--
        return ne!!
    }

    override fun equals(other: Any?): Boolean {
        if (other === this) return true
        if (other !is List<*>) return false

        return orderedEquals(this, other)
    }

    override fun hashCode(): Int = orderedHashCode(this)

    override fun toString(): String = StringBuilder().also {
        it.append("[ ")
        this.forEach { item -> it.append("$item ") }
        it.append(" ]")
    }.toString()

    internal companion object {
        /**
         * 节点类
         * */
        private data class Node<T>(
            var item: T?,
            var prev: Node<T>? = null,
            var next: Node<T>? = null
        )

        /**
         * 查看element是否合法
         * */
        internal fun checkElementIndex(index: Int, size: Int) {
            if (index < 0 || index >= size) {
                throw IndexOutOfBoundsException("index: $index, size: $size")
            }
        }

        /**
         * 查看位置是否合法
         * */
        internal fun checkPositionIndex(index: Int, size: Int) {
            if (index < 0 || index > size) {
                throw IndexOutOfBoundsException("index: $index, size: $size")
            }
        }

        /**
         * 查看范围是否合法
         *  */
        internal fun checkRangeIndexes(fromIndex: Int, toIndex: Int, size: Int) {
            if (fromIndex < 0 || toIndex > size) {
                throw IndexOutOfBoundsException("fromIndex: $fromIndex, toIndex: $toIndex, size: $size")
            }
            if (fromIndex > toIndex) {
                throw IllegalArgumentException("fromIndex: $fromIndex > toIndex: $toIndex")
            }
        }

        /**
         * 查看边界是否合法
         * */
        internal fun checkBoundsIndexes(startIndex: Int, endIndex: Int, size: Int) {
            if (startIndex < 0 || endIndex > size) {
                throw IndexOutOfBoundsException("startIndex: $startIndex, endIndex: $endIndex, size: $size")
            }
            if (startIndex > endIndex) {
                throw IllegalArgumentException("startIndex: $startIndex > endIndex: $endIndex")
            }
        }

        /**
         * 哈希函数
         * */
        internal fun orderedHashCode(c: Collection<*>): Int {
            var hashCode = 1
            for (e in c) {
                hashCode = 31 * hashCode + (e?.hashCode() ?: 0)
            }
            return hashCode
        }

        /**
         * 查看是否相等
         * */
        internal fun orderedEquals(c: Collection<*>, other: Collection<*>): Boolean {
            if (c.size != other.size) return false

            val otherIterator = other.iterator()
            for (elem in c) {
                val elemOther = otherIterator.next()
                if (elem != elemOther) {
                    return false
                }
            }
            return true
        }
    }

    /**
     * 迭代器类
     * */
    private open inner class LinkedIterator(
        protected var index: Int = 0,
        protected var current: Node<T>? = null
    ) : MutableIterator<T> {

        override fun hasNext(): Boolean = index < _size

        override fun next(): T {
            if (!hasNext()) {
                throw NoSuchElementException()
            }
            val item = current?.item
            current = current?.next
            index++
            return item!!
        }

        override fun remove() {
        }
    }

    /**
     * 列表迭代器类
     * */
    private open inner class LinkedListIterator(
        index: Int = 0,
        cur: Node<T>? = null
    ) : LinkedIterator(
        index,
        cur
    ), MutableListIterator<T> {

        init {
            checkPositionIndex(index, _size)
        }

        override fun hasPrevious(): Boolean = index > 0

        override fun nextIndex(): Int = index

        override fun previous(): T {
            if (!hasPrevious()) {
                throw NoSuchElementException()
            }
            val item = current?.item
            current = current?.prev
            index--
            return item!!
        }

        override fun previousIndex(): Int = index - 1

        override fun add(element: T) {


            index++
        }

        override fun set(element: T) {
            current!!.item = element
        }
    }
}