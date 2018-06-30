//
// Created by alex on 21.05.18.
//

#ifndef PYSTL_ZIP_H
#define PYSTL_ZIP_H

#include <tuple>

namespace PySTL {
    template <class ... Args>
    class zip_impl;

    template <class HeadType, class ... Args>
    class zip_impl<HeadType, Args...> {
        using HeadValueType = std::tuple<typename std::remove_reference<HeadType>::type::value_type&>;
        using TailValueType = typename zip_impl<Args...>::value_type;
        HeadType& Head;
        zip_impl<Args...> Tail;

    public:
        using value_type = decltype(std::tuple_cat(std::declval<HeadValueType>(), std::declval<TailValueType>()));

        class ZipIterator {
            using HeadIterType = typename std::remove_reference<HeadType>::type::iterator;
            using TailIterType = typename zip_impl<Args...>::ZipIterator;
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

        zip_impl(HeadType& head, Args& ... args) :
            Head(head), Tail(args...) {}

        auto begin() {
            return ZipIterator(Head.begin(), Tail.begin());
        }

        auto end() {
            return ZipIterator(Head.end(), Tail.end());
        }
    };

    template <>
    class zip_impl<> {
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
    zip_impl<Args...> zip(Args&& ... args) {
        return zip_impl<Args...>(args...);
    }
};

#endif //PYSTL_ZIP_H
