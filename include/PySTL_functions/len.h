//
// Created by alex on 21.05.18.
//

#ifndef PYSTL_LEN_H
#define PYSTL_LEN_H

namespace PySTL {
    template<class T>
    int len(const T &collection) {
        return collection.size();
    }
}

#endif //PYSTL_LEN_H
