//
// Created by alex on 21.05.18.
//

#ifndef PYSTL_ENUMERATE_H
#define PYSTL_ENUMERATE_H

#include <tuple>
#include <type_traits>
#include <memory>

#include <len.h>

namespace PySTL {

    namespace {
        template<typename T>
        std::unique_ptr<typename std::remove_reference<T>::type > rvalueToPtr(T && collection) {
            using CollectionType = typename std::remove_reference<T>::type;
            return std::unique_ptr<CollectionType>(new CollectionType(collection));
        }
    }

    template<class T>
    class enumerate {
        std::unique_ptr<typename std::remove_reference<T>::type > FakeCollection;
        T & Collection;
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

            EnumerateIterator& operator++() {
                ++Idx;
                ++CollectionIter;
                return *this;
            }

            bool operator==(const EnumerateIterator & it) const {
                return CollectionIter == it.CollectionIter && Idx == it.Idx;
            }

            bool operator!=(const EnumerateIterator & it) const {
                return !(*this == it);
            }
        };

    public:
        explicit enumerate(T && collection, const int start=0) :
            FakeCollection(rvalueToPtr(collection)), Collection(*FakeCollection), Start(start) {}
        explicit enumerate(T & collection, const int start=0) : Collection(collection), Start(start) {}

        EnumerateIterator<decltype(Collection.begin())> begin() {
            return EnumerateIterator<decltype(Collection.begin())>(Start, Collection.begin());
        }

        EnumerateIterator<decltype(Collection.begin())> end() {
            return EnumerateIterator<decltype(Collection.begin())>(Start + len(Collection), Collection.end());
        }
    };
}

#endif //PYSTL_ENUMERATE_H
