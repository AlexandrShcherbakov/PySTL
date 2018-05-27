//
// Created by alex on 21.05.18.
//

#ifndef PYSTL_ZIP_H
#define PYSTL_ZIP_H

#include <tuple>

namespace PySTL {
    template <class ... Args>
    class _zip_impl;

    template <class HeadType, class ... Args>
    class _zip_impl<HeadType, Args...> {
        using HeadValueType = std::tuple<typename HeadType::value_type&>;
        using TailValueType = typename _zip_impl<Args...>::value_type;
        HeadType& Head;
        _zip_impl<Args...> Tail;

    public:
        using value_type = decltype(std::tuple_cat(std::declval<HeadValueType>(), std::declval<TailValueType>()));

        class ZipIterator {
            using HeadIterType = typename HeadType::iterator;
            using TailIterType = typename _zip_impl<Args...>::ZipIterator;
            HeadIterType Head;
            TailIterType Tail;
        public:
            ZipIterator(const HeadIterType& head, const TailIterType& tail) :
                Head(head),
                Tail(tail) {
            }

            value_type operator*() {
                return std::tuple_cat(HeadValueType(*Head), *Tail);
            }

            ZipIterator& operator++() {
                ++Head;
                ++Tail;
                return (*this);
            }

            ZipIterator operator++(int) {
                auto copy = (*this);
                ++(*this);
                return copy;
            }

            bool operator==(const ZipIterator& it) const {
                return Head == it.Head && Tail == it.Tail;
            }

            bool operator!=(const ZipIterator& it) const {
                return !(*this == it);
            }
        };

        _zip_impl(HeadType& head, Args& ... args) :
            Head(head), Tail(args...) {}

        auto begin() {
            return ZipIterator(Head.begin(), Tail.begin());
        }

        auto end() {
            return ZipIterator(Head.end(), Tail.end());
        }
    };

    template <>
    class _zip_impl<> {
    public:
        class ZipIterator {
        public:
            std::tuple<> operator*() {
                return std::tuple<>();
            }

            ZipIterator& operator++() {
                return (*this);
            }

            ZipIterator operator++(int) {
                auto copy = (*this);
                ++(*this);
                return copy;
            }

            bool operator==(const ZipIterator& it) const {
                return true;
            }

            bool operator!=(const ZipIterator& it) const {
                return !(*this == it);
            }
        };

        using value_type = std::tuple<>;

        auto begin() {
            return ZipIterator();
        }

        auto end() {
            return ZipIterator();
        }
    };

    template<class ... Args>
    _zip_impl<Args...> zip(Args& ... args) {
        return _zip_impl<Args...>(args...);
    }
};

#endif //PYSTL_ZIP_H
