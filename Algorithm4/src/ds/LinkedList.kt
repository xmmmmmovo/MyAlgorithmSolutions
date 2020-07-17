package ds

import com.sun.org.apache.xpath.internal.operations.Bool
import kotlin.NoSuchElementException

/**
 * 双向链表
 * */
class LinkedList<T> : MutableList<T> {
    private var first: Node<T>? = null
    private var last: Node<T>? = null
    private var _size: Int = 0

    /**
     * 在尾部插入[element]
     * */
    override fun add(element: T): Boolean {
        linkedLast(element)
        return true
    }

    /**
     * 让[element]成为[index]位置的节点
     * */
    override fun add(index: Int, element: T) {
        checkPositionIndex(index, size)
        if (index == _size) {
            linkedLast(element)
        } else {
            linkedBefore(element, getNode(index))
        }
    }

    /**
     * 让[index]位置成为[elements]的第一个节点位置
     * */
    override fun addAll(index: Int, elements: Collection<T>): Boolean {
        checkPositionIndex(index, size)

        if (elements.isEmpty()) {
            return false
        }

        // 这里的两个节点代表着插入节点的前后节点
        var pred: Node<T>?
        var succ: Node<T>?

        // 判断是否是最尾部插入
        if (index == _size) {
            succ = null
            pred = last
        } else {
            succ = getNode(index)
            pred = succ.prev
        }

        for (e in elements) {
            val nNode = Node(e, pred, null)
            if (pred == null) {
                // 说明是在首节点插入的
                first = nNode
            } else {
                // 一直往后插入
                pred.next = nNode
            }
            pred = nNode
        }

        if (succ == null) {
            last = pred
        } else {
            pred!!.next = succ
            succ.prev = pred
        }

        _size += elements.size
        return true
    }

    /**
     * 在尾部添加[elements]
     * */
    override fun addAll(elements: Collection<T>): Boolean =
        addAll(_size, elements)

    /**
     * 清除所有节点
     * */
    override fun clear() {
        var n = first
        while (n != null) {
            val next = n.next
            // 快速gc
            n.item = null
            n.next = null
            n.prev = null
            n = next
        }
        first = null
        last = null
        _size = 0
    }

    /**
     * 删除为[element]的节点
     * */
    override fun remove(element: T): Boolean {
        var node = first
        while (node != null) {
            if (node.item == element) {
                unlink(node)
                return true
            }
            node = node.next
        }

        return false
    }

    /**
     * 删除
     * */
    override fun removeAll(elements: Collection<T>): Boolean =
        if (containsAll(elements)) elements.all {
            remove(it)
        } else false


    /**
     * 删除[index]位置的节点
     * */
    override fun removeAt(index: Int): T {
        checkElementIndex(index, size)
        val node = getNode(index)
        val item = node.item
        unlink(node)
        return item ?: throw NoSuchElementException()
    }

    override fun retainAll(elements: Collection<T>): Boolean =
        if (containsAll(elements)) {
            clear()
            addAll(elements)
        } else false

    /**
     * 设定[index]为[element]并返回旧值
     * */
    override fun set(index: Int, element: T): T {
        checkElementIndex(index, size)
        return getNode(index).run {
            item!!.also {
                item = element
            }
        }
    }

    /**
     * 是否包含[element]
     * */
    override fun contains(element: T): Boolean {
        return indexOf(element) != -1
    }

    /**
     * 是否包含所有[elements]
     * */
    override fun containsAll(elements: Collection<T>): Boolean =
        if (elements.isEmpty())
            false
        else
            elements.all {
                contains(it)
            }

    /**
     * 获取[index]节点数据
     * */
    override fun get(index: Int): T {
        checkElementIndex(index, size)
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
        var index = _size - 1
        var node = last
        while (node != null) {
            if (node.item == element) {
                return index
            }
            index--
            node = node.prev
        }
        return index
    }

    /**
     * 返回迭代器
     * */
    override fun iterator(): MutableIterator<T> {
        return LinkedIterator(0)
    }

    /**
     * 返回列表迭代器
     * */
    override fun listIterator(): MutableListIterator<T> {
        return LinkedListIterator(0)
    }


    /**
     * 返回从某个index开始的迭代器
     * */
    override fun listIterator(index: Int): MutableListIterator<T> {
        checkElementIndex(index, size)
        return LinkedListIterator(index)
    }

    /**
     * 返回子列表
     * */
    override fun subList(fromIndex: Int, toIndex: Int): MutableList<T> {
        checkRangeIndexes(fromIndex, toIndex, size)
        val res = LinkedList<T>()
        var i = fromIndex
        var n = getNode(fromIndex)
        while (i < toIndex) {
            res.add(n.item!!)
            i++
            n = n.next!!
        }
        return res
    }

    /**
     * 获取链表长度
     * */
    override val size: Int
        get() = _size

    /**
     * 获取首节点数据
     * */
    fun getFirst(): T = first?.item ?: throw NoSuchElementException()

    /**
     * 获取尾节点数据
     * */
    fun getLast(): T = last?.item ?: throw NoSuchElementException()

    /**
     * 反转链表
     * */
    fun reverse() {
        if (first == null) {
            return
        }
        first = last.also {
            last = first
        }
        var n = first

        while (n != null) {
            n.prev = n.next.also {
                n!!.next = n!!.prev
            }
            n = n.next
        }
    }

    /**
     * 添加首节点
     * */
    fun addFirst(element: T) {
        linkedFirst(element)
    }

    /**
     * 添加尾节点
     * */
    fun addLast(element: T) {
        linkedLast(element)
    }

    /**
     * 删除首节点
     * */
    fun removeFirst(): T = unlinkFirst()

    /**
     * 删除尾节点
     * */
    fun removeLast(): T = unlinkLast()

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
     * 连接首节点
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
     * 连接到[node]节点前面
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
     * 连接尾节点
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

    /**
     * 解除首部连接
     * */
    private fun unlinkFirst(): T {
        val f = first ?: throw NoSuchElementException()
        val item = f.item
        val next = f.next
        // 快速GC
        f.next = null
        f.item = null
        first = next
        if (next == null) {
            last = null
        } else {
            next.prev = null
        }

        _size--
        return item!!
    }

    /**
     * 解除尾部连接
     * */
    private fun unlinkLast(): T {
        val l = last ?: throw NoSuchElementException()
        val item = l.item
        val prev = l.prev
        // 快速GC
        l.item = null
        l.prev = null
        last = prev
        if (prev == null) {
            first = null
        } else {
            prev.next = null
        }
        _size--
        return item!!
    }

    /**
     * 解连接
     * */
    private fun unlink(node: Node<T>): T {
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

    /**
     * " == " 方法
     * */
    override fun equals(other: Any?): Boolean {
        if (other === this) return true
        if (other !is List<*>) return false

        return orderedEquals(this, other)
    }

    /**
     * hash计算
     * */
    override fun hashCode(): Int = orderedHashCode(this)

    /**
     * 转字符串方法
     * */
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
        protected var index: Int = 0
    ) : MutableIterator<T> {
        protected var lastReturned: Node<T>? = null
        protected var current: Node<T>? = null

        init {
            checkPositionIndex(index, _size)
            current = if (index == _size) null else getNode(index)
        }

        /**
         * 是否存在下一个节点
         * */
        override fun hasNext(): Boolean = index < _size

        /**
         * 下一节点数据
         * */
        override fun next(): T {
            if (!hasNext()) {
                throw NoSuchElementException()
            }
            lastReturned = current
            current = current?.next
            index++
            return lastReturned?.item ?: throw NoSuchElementException()
        }

        /**
         * 删除当前节点
         * */
        override fun remove() {
            val lastNext = lastReturned?.next
            unlink(lastReturned ?: throw IllegalStateException())
            index--
        }
    }

    /**
     * 列表迭代器类
     * */
    private open inner class LinkedListIterator(
        index: Int = 0
    ) : LinkedIterator(
        index
    ), MutableListIterator<T> {

        /**
         * 是否有上一节点
         * */
        override fun hasPrevious(): Boolean = index > 0

        /**
         * 下一节点游标
         * */
        override fun nextIndex(): Int = index

        /**
         * 返回上一节点
         * */
        override fun previous(): T {
            if (!hasPrevious()) {
                throw NoSuchElementException()
            }
            current = if (current == null) last else current!!.prev
            lastReturned = current
            return lastReturned?.item ?: throw NoSuchElementException()
        }

        /**
         * 下一节点游标
         * */
        override fun previousIndex(): Int = index - 1

        /**
         * 添加节点
         * */
        override fun add(element: T) {
            lastReturned = null
            if (current == null) {
                linkedLast(element)
            } else {
                linkedBefore(element, current!!)
            }
            index++
        }

        /**
         * 设置节点
         * */
        override fun set(element: T) {
            if (lastReturned == null)
                throw IllegalStateException()
            current!!.item = element
        }
    }
}