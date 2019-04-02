//
// Created by alex on 02.04.2019.
//

#ifndef PYSTL_ANY_H
#define PYSTL_ANY_H

namespace PySTL {
    template<typename T>
    bool any(const T& iterable) {
        for (const auto& value : iterable) {
            if (value) {
                return true;
            }
        }
        return false;
    }
}

#endif //PYSTL_ANY_H
