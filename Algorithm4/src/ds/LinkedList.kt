package ds

import java.util.*
import kotlin.NoSuchElementException

class LinkedList<T> : MutableList<T> {
    private var first: Node<T>? = null
    private var last: Node<T>? = null
    private var _size: Int = 0

    override val size: Int
        get() = _size

    fun getFirst(): T {
        if (first == null)
            throw NoSuchElementException()
        return first!!.item
    }

    fun getLast(): T {
        if (last == null)
            throw NoSuchElementException()
        return last!!.item
    }

    override fun add(element: T): Boolean {
        TODO("Not yet implemented")
    }

    override fun add(index: Int, element: T) {
        TODO("Not yet implemented")
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
        return first!!.item
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
    override fun isEmpty(): Boolean {
        return first == null
    }

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
        TODO("Not yet implemented")
    }

    /**
     * 返回列表迭代器
     * */
    override fun listIterator(): MutableListIterator<T> {
        TODO("Not yet implemented")
    }


    /**
     * 返回从某个index开始的迭代器
     * */
    override fun listIterator(index: Int): MutableListIterator<T> {
        TODO("Not yet implemented")

    }

    /**
     * 返回子列表
     * */
    override fun subList(fromIndex: Int, toIndex: Int): MutableList<T> {
        TODO("Not yet implemented")
    }

    companion object {
        private data class Node<T>(
            val item: T,
            var next: Node<T>? = null,
            var prev: Node<T>? = null
        )
    }

    private class LinkedListIterator<T>(
        private var current: Node<T>?
    ) : MutableListIterator<T> {
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

        override fun hasPrevious(): Boolean {
            TODO("Not yet implemented")
        }

        override fun nextIndex(): Int {
            TODO("Not yet implemented")
        }

        override fun previous(): T {
            TODO("Not yet implemented")
        }

        override fun previousIndex(): Int {
            TODO("Not yet implemented")
        }

        override fun add(element: T) {
            TODO("Not yet implemented")
        }

        override fun remove() {
            TODO("Not yet implemented")
        }

        override fun set(element: T) {
            TODO("Not yet implemented")
        }
    }
}