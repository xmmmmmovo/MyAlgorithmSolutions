//
// Created by xmmmmmovo on 2020/5/8.
//

#ifndef DS_FUNCTIONAL_HPP
#define DS_FUNCTIONAL_HPP

#include <utility>
namespace ds {

template<typename r, typename p>
auto filter(r &&range, p &&predicate) {
    using iter_type     = decltype(range.begin());
    using sentinel_type = decltype(range.end());

    struct filter_t final {
        struct sentinel final {};
        struct iterator final {
            filter_t &parent;
            iter_type iter;
            iterator &operator++() {
                ++iter;
                to_next();
                return *this;
            }
            decltype(auto) operator*() const { return *iter; }
            bool           operator!=(const iterator &ri) const {
                return iter != ri.iter;
            }
            bool operator!=(sentinel) const {
                return iter != parent.range_end;
            }
            void to_next() {
                while (iter != parent.range_end && !parent.predicate(*iter)) {
                    ++iter;
                }
            }
        };
        iterator begin() {
            iterator result{
                    *this,
                    range.begin()};
            result.to_next();
            return result;
        }
        r             range;
        p             predicate;
        sentinel_type range_end = range.end();
        sentinel      end() const { return {}; };
    } result{std::forward<r>(range), std::forward<p>(predicate)};
    return result;
}

}// namespace ds

#endif//DS_FUNCTIONAL_HPP
