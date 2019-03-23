//
// Created by alex on 21.01.2019.
//

#ifndef PYSTL_SUM_H
#define PYSTL_SUM_H

namespace PySTL {
    template <typename T, typename U>
    U sum(const T &iterable, U start = U()) {
        for (const auto& value : iterable) {
            start += value;
        }
        return start;
    }

    template <typename T>
    auto sum(const T &iterable) {
        typename T::value_type start = 0;
        for (const auto& value : iterable) {
            start += value;
        }
        return start;
    }

    template <typename T, int N>
    auto sum(const T (&iterable)[N], T result = T()) {
//        T result = T();
        for (int i = 0; i < N; ++i) {
            result += iterable[i];
        }
        return result;
    }
}

#endif //PYSTL_SUM_H
