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
    auto enumerate(const T & collection, const int start=0) {
        std::vector<std::tuple<int, typename T::value_type> > result;
        for (int i = 0; i < len(collection); ++i) {
            result.emplace_back(std::make_tuple(i + start, collection[i]));
        }
        return result;
    }
}

#endif //PYSTL_MAIN_H
