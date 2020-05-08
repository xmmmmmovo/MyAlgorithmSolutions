//
// Created by xmmmmmovo on 2020/5/8.
//

#ifndef DS_ITOA_HPP
#define DS_ITOA_HPP

namespace ds {

using std::size_t;

struct itoa_t final {
    struct sentinel final {};
    struct iterator final {
        size_t value = 0;

        iterator &operator++() {
            ++value;
            return *this;
        }

        size_t operator*() const {
            return value;
        }

        bool operator!=(const iterator &ri) const {
            return value != ri.value;
        }

        bool operator!=(sentinel) const {
            return true;
        }
    };
    iterator begin() const { return {}; }
    iterator end() const { return {}; }
} inline const itoa;

}// namespace ds

#endif// DS_ITOA_HPP
