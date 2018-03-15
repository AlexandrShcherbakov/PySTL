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


TEST(ArrayEnumerate__Test, EnumerateFunction) {
    std::array<float, 3> v = {1, 2, 3};
    auto enumObject = PySTL::enumerate(v);
    ASSERT_EQ(PySTL::len(enumObject), PySTL::len(v));
    for (auto it : enumObject) {
        ASSERT_EQ(std::get<1>(it), v[std::get<0>(it)]);
    }
    enumObject = PySTL::enumerate(v, 1);
    ASSERT_EQ(std::get<0>(enumObject.back()), PySTL::len(v));
}

TEST(StringEnumerate__Test, EnumerateFunction) {
    std::string v = "Test string";
    auto enumObject = PySTL::enumerate(v);
    ASSERT_EQ(PySTL::len(enumObject), PySTL::len(v));
    for (auto it : enumObject) {
        ASSERT_EQ(std::get<1>(it), v[std::get<0>(it)]);
    }
    enumObject = PySTL::enumerate(v, 1);
    ASSERT_EQ(std::get<0>(enumObject.back()), PySTL::len(v));
}
