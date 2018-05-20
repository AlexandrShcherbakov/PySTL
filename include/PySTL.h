//
// Created by alex on 13.03.18.
//

#ifndef PYSTL_MAIN_H
#define PYSTL_MAIN_H

#include <tuple>

namespace PySTL {
    template<class T>
    int len(const T &collection) {
        return collection.size();
    }

    template<class T>
    class enumerate {
        T & Collection;
        T FakeCollection;
        const int Start;

        template<class IterType>
        class EnumerateIterator {
            IterType CollectionIter;
            int Idx;
            using ValueType = std::tuple<int, decltype(*CollectionIter)&>;
        public:
            EnumerateIterator(const int idx, const IterType collectionIter):
                Idx(idx), CollectionIter(collectionIter) {}

            ValueType operator*() {
                return ValueType(Idx, *CollectionIter);
            }

            void operator++() {
                Idx++;
                CollectionIter++;
            }

            bool operator==(const EnumerateIterator & it) const {
                return CollectionIter == it.CollectionIter && Idx == it.Idx;
            }

            bool operator!=(const EnumerateIterator & it) const {
                return !(*this == it);
            }
        };

    public:
        enumerate(T && collection, const int start=0) :
            FakeCollection(collection), Collection(FakeCollection), Start(start) {}
        enumerate(T & collection, const int start=0) : Collection(collection), Start(start) {}

        EnumerateIterator<decltype(Collection.begin())> begin() {
            return EnumerateIterator<decltype(Collection.begin())>(Start, Collection.begin());
        }

        EnumerateIterator<decltype(Collection.begin())> end() {
            return EnumerateIterator<decltype(Collection.begin())>(Start + len(Collection), Collection.end());
        }
    };

    class range {
        const int Begin, End, Step;

        class RangeIterator {
            int Idx;
            const int Begin, End, Step;
        public:
            RangeIterator(const int idx, const int begin, const int end, const int step):
                Idx(idx), Begin(begin), End(end), Step(step) {}

            int& operator*() {
                return Idx;
            }

            const int& operator*() const {
                return Idx;
            }

            const RangeIterator& operator++() {
                Idx += Step;
                return *this;
            }

            const RangeIterator operator++(int) {
                auto copy = *this;
                Idx += Step;
                return copy;
            }

            bool operator==(const RangeIterator & it) const {
                /// All iterators out of range are equal
                const bool firstOutOfRange = Step * (End - Idx) <= 0;
                const bool secondOutOfRange = it.Step * (it.End - it.Idx) <= 0;
                return (Idx == it.Idx || firstOutOfRange && secondOutOfRange)
                    && Step == it.Step
                    && Begin == it.Begin
                    && End == it.End;
            }

            bool operator!=(const RangeIterator & it) const {
                return !(*this == it);
            }
        };
    public:
        using value_type = int;
        using iterator = RangeIterator;
        using const_iterator = RangeIterator;
        range(const int begin, const int end, const int step=1): Begin(begin), End(end), Step(step) {
            assert(Step);
        }
        range(const int end) : range(0, end) {}

        iterator begin() {
            return iterator(Begin, Begin, End, Step);
        }

        iterator end() {
            return iterator(End, Begin, End, Step);
        }

        int size() const {
            return (End - Begin + Step - 1) / Step;
        }
    };

    template <class ... Args>
    class _zip_impl;

    template <class HeadType, class ... Args>
    class _zip_impl<HeadType, Args...> {
        using HeadValueType = std::tuple<typename HeadType::value_type&>;
        using TailValueType = typename _zip_impl<Args...>::value_type;
        HeadType Head;
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

        _zip_impl(const HeadType& head, const Args& ... args) :
            Head(head), Tail(args...) {}

        auto begin() {
            return ZipIterator(Head.begin(), Tail.begin());
        }

        auto end() {
            return ZipIterator(Head.end(), Tail.end());
        }
    };

    template <class HeadType>
    class _zip_impl<HeadType> {
        using HeadValueType = std::tuple<typename HeadType::value_type&>;
        HeadType Head;

    public:
        class ZipIterator {
            using HeadIterType = typename HeadType::iterator;
            HeadIterType Head;
        public:
            ZipIterator(const HeadIterType& head) :
                    Head(head) {
            }

            HeadValueType operator*() {
                return HeadValueType(*Head);
            }

            ZipIterator& operator++() {
                ++Head;
                return (*this);
            }

            ZipIterator operator++(int) {
                auto copy = (*this);
                ++(*this);
                return copy;
            }

            bool operator==(const ZipIterator& it) const {
                return Head == it.Head;
            }

            bool operator!=(const ZipIterator& it) const {
                return !(*this == it);
            }
        };

        using value_type = HeadValueType;

        _zip_impl(const HeadType& head) :
                Head(head) {}

        auto begin() {
            return ZipIterator(Head.begin());
        }

        auto end() {
            return ZipIterator(Head.end());
        }
    };

    template<class ... Args>
    _zip_impl<Args...> zip(Args ... args) {
        return _zip_impl<Args...>(args...);
    }
};

#endif //PYSTL_MAIN_H
