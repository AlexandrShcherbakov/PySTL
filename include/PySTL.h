//
// Created by alex on 13.03.18.
//

#ifndef PYSTL_MAIN_H
#define PYSTL_MAIN_H

#include <tuple>
#include <vector>

namespace PySTL {
    template<class T>
    int len(const T &collection) {
        return collection.size();
    }

    template<class T>
    class enumerate {
        using iterator_value_type = std::tuple<int, typename T::value_type&>;
        T & Collection;
        const int Start;

        class EnumerateIterator {
            int Idx, RealIdx;
            T & Collection;
        public:
            EnumerateIterator(T & collection, const int idx, const int realIdx):
                Collection(collection), Idx(idx), RealIdx(realIdx) {}

            iterator_value_type operator*() {
                return iterator_value_type(Idx, Collection[RealIdx]);
            }

            void operator++() {
                Idx++;
                RealIdx++;
            }

            bool operator==(const EnumerateIterator & it) const {
                return &Collection == &(it.Collection) && RealIdx == it.RealIdx && Idx == it.Idx;
            }

            bool operator!=(const EnumerateIterator & it) const {
                return !(*this == it);
            }
        };

    public:
        enumerate(T & collection, const int start=0) : Collection(collection), Start(start) {}

        EnumerateIterator begin() {
            return EnumerateIterator(Collection, Start, 0);
        }

        EnumerateIterator end() {
            const int lenCollection = len(Collection);
            return EnumerateIterator(Collection, Start + lenCollection, lenCollection);
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

            int operator*() {
                return Idx;
            }

            void operator++() {
                Idx += Step;
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
        range(const int begin, const int end, const int step=1): Begin(begin), End(end), Step(step) {
            assert(Step);
        }
        range(const int end) : range(0, end) {}

        RangeIterator begin() {
            return RangeIterator(Begin, Begin, End, Step);
        }

        RangeIterator end() {
            return RangeIterator(End, Begin, End, Step);
        }
    };
}

#endif //PYSTL_MAIN_H
