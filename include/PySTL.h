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
}

#endif //PYSTL_MAIN_H
