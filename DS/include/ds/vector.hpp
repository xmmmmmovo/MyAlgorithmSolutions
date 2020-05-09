//
// Created by xmmmmmovo on 2020/3/26.
//

#ifndef DS_VECTOR_HPP
#define DS_VECTOR_HPP

#include <algorithm>
#include <iostream>

namespace ds {

using std::copy_n;
using std::exchange;
using std::max;
using std::move;
using std::size_t;

template<typename T>
class vector {
private:
    T *first_ = nullptr;
    T *last_  = nullptr;
    T *end_   = nullptr;

    void alloc_and_move(const size_t new_capacity) {
        T *new_first = new T[ new_capacity ];
        last_        = move(first_, last_, new_first);
        delete[] first_;
        first_ = new_first;
        end_   = first_ + new_capacity;
    }

    size_t calcu_growth(const size_t new_size) const {
        const size_t geometric = capacity() + capacity() / 2;
        return max(geometric, new_size);
    }

    void grow_if_needed(const size_t new_size) {
        if (new_size <= capacity()) {
            return;
        }
        alloc_and_move(calcu_growth(new_size));
    }

public:
    vector() = default;

    explicit vector(const size_t size)
        : first_(new T[ size ]()), last_(first_ + size) {}

    ~vector() noexcept { delete[] first_; }

    vector(const vector &other) {
        first_ = new T[ other.size() ];
        end_ = last_ = std::copy(other.first_, other.last_, first_);// 深拷贝
    }

    vector &operator=(const vector &other) {
        if (&other == this) {
            return *this;
        }

        delete[] first_;
        first_ = new T[ other.size() ];
        end_ = last_ = std::copy(other.first_, other.last_, first_);
        return *this;
    }

    vector(const vector &&other) noexcept
        : first_(exchange(other.first_, 0)),
          last_(exchange(other.last_, nullptr)),
          end_(exchange(other.end_, nullptr)) {}

    vector &operator=(const vector &&other) {
        delete[] first_;
        first_ = std::exchange(other.first_, nullptr);
        last_  = std::exchange(other.last_, nullptr);
        end_   = std::exchange(other.end_, nullptr);
        return *this;
    }

    T &operator[](const size_t index) {
        return first_[ index ];
    }

    const T &operator[](const size_t index) const {
        return first_[ index ];
    }

    size_t size() const {
        return last_ - first_;
    }

    size_t capacity() const {
        return end_ - first_;
    }

    T &emplace_back(const T &value) {
        grow_if_needed(size() + 1);
        return *last_++ = value;
    }

    T &emplace_back(T &&value) {
        grow_if_needed(size() + 1);
        return *last_++ = std::move(value);
    }

    void clear() {
        last_ = first_;
    }

    void resize(const size_t new_size) {
        reserve(new_size);
    }

    void reserve(const size_t new_capacity) {
        if (new_capacity > capacity()) {
            alloc_and_move(new_capacity);
        }
    }

    void shrink_to_fit() {
        if (capacity() != size()) {
            alloc_and_move(size());
        }
    }
};

}// namespace ds

#endif// DS_VECTOR_HPP
