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
        using iterator_value_type = std::tuple<int, typename T::value_type>;
        T & Collection;
        const int Start;

        class EnumerateIterator {
            int Idx, RealIdx;
            T & Collection;
        public:
            EnumerateIterator(T & collection, const int idx, const int realIdx):
                Collection(collection), Idx(idx), RealIdx(realIdx) {}

            iterator_value_type operator*() {
                return std::make_tuple(Idx, Collection[RealIdx]);
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
}

#endif //PYSTL_MAIN_H
