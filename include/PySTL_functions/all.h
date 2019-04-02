//
// Created by alex on 24.03.2019.
//

#ifndef PYSTL_ALL_H
#define PYSTL_ALL_H

namespace PySTL {
    template<typename T>
    bool all(const T& iterable) {
        for (const auto& value : iterable) {
            if (!value) {
                return false;
            }
        }
        return true;
    }
}

#endif //PYSTL_ALL_H
