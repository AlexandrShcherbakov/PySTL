//
// Created by alex on 21.05.18.
//

#ifndef PYSTL_ENUMERATE_H
#define PYSTL_ENUMERATE_H

#include <tuple>

#include <len.h>

namespace PySTL {

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
}

#endif //PYSTL_ENUMERATE_H
