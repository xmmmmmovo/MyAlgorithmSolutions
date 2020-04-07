//
// Created by xmmmmmovo on 2020/3/26.
//

#ifndef DS_VECTOR_HPP
#define DS_VECTOR_HPP

#include <exception>
#include <iostream>
#include <string>

namespace ds {
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

template <typename T>
class vector {
  public:
    vector();

    virtual ~vector();

    vector(size_t size);

    vector(size_t size, T value);

    size_t size();

    void append(T x);

    T &operator[](size_t index) {
        int i = (int)index;
        if (i > _size || i < -_size) {
            throw std::out_of_range("数组越界 out of range");
        }

        if (i < 0) {
            return elem[ _size + i ];
        }

        return elem[ i ];
    }

    T &operator[](string s) {}

    friend ostream &operator<<(ostream &o, vector<T> &v) {
        int j = 0;
        o << "[";
        for (; j < v._size - 1; ++j) {
            o << v.elem[ j ] << ", ";
        }
        o << v.elem[ j ] << "]";
        return o;
    }

  private:
    T *    elem;
    size_t _size;
    size_t it;

    void _append(T &t);

    void _alloc();
};

template <typename T>
inline size_t vector<T>::size() {
    return _size;
}

template <typename T>
vector<T>::vector() {
    it    = 16; // 对齐
    elem  = new T[ it ];
    _size = 0;
}

template <typename T>
vector<T>::~vector() {
#ifdef DEBUG
    cout << "析构函数执行" << endl;
#endif
}

template <typename T>
vector<T>::vector(size_t size) {
    it    = size;
    elem  = new T[ size ];
    _size = 0;
}

template <typename T>
vector<T>::vector(size_t size, T value) {
    it   = size;
    elem = new T[ size ];
    for (int i = 0; i < size; ++i) {
        elem[ i ] = value;
    }
    _size = size;
}

template <typename T>
void vector<T>::append(T x) {
    _append(x);
}

template <typename T>
void vector<T>::_append(T &t) {
    if (++_size > it) {
        _alloc();
    }
    elem[ _size - 1 ] = t;
}

template <typename T>
void vector<T>::_alloc() {
    T *tmp = elem;
    try {
        elem = new T[ it <<= 2u ];
    } catch (std::bad_alloc &e) {
        throw e;
    }
    for (int i = 0; i < _size - 1; ++i) {
        elem[ i ] = tmp[ i ];
    }
    delete[] tmp;
}

} // namespace ds

#endif // DS_VECTOR_HPP
