//
// Created by alex on 14.03.18.
//

#include "gtest/gtest.h"

#include "../include/PySTL.h"

TEST(VectorEnumerate__Test, EnumerateFunction) {
    std::vector<float> v(10, 1e-4f);
    auto enumObject = PySTL::enumerate(v);
    ASSERT_EQ(PySTL::len(enumObject), PySTL::len(v));
    for (auto it : enumObject) {
        ASSERT_EQ(std::get<1>(it), v[std::get<0>(it)]);
    }
    enumObject = PySTL::enumerate(v, 1);
    ASSERT_EQ(std::get<0>(enumObject.back()), PySTL::len(v));
}