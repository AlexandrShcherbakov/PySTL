//
// Created by alex on 14.03.18.
//

#include "gtest/gtest.h"

#include "../include/PySTL_functions/enumerate.h"
#include "../include/PySTL_functions/range.h"

using namespace PySTL;

TEST(VectorEnumerate__Test, EnumerateFunction) {
    std::vector<float> v(10, 1e-4f);
    for (auto it : enumerate(v)) {
        ASSERT_EQ(std::get<1>(it), v[std::get<0>(it)]);
        ASSERT_EQ(&std::get<1>(it), &v[std::get<0>(it)]);
    }
    ASSERT_EQ(0, std::get<0>(*enumerate(v).begin()));
    ASSERT_EQ(v[0], std::get<1>(*enumerate(v).begin()));
}


TEST(ArrayEnumerate__Test, EnumerateFunction) {
    std::array<float, 3> v = {1, 2, 3};
    for (auto it : enumerate(v)) {
        ASSERT_EQ(std::get<1>(it), v[std::get<0>(it)]);
        ASSERT_EQ(&std::get<1>(it), &v[std::get<0>(it)]);
    }
    ASSERT_EQ(0, std::get<0>(*enumerate(v).begin()));
    ASSERT_EQ(v[0], std::get<1>(*enumerate(v).begin()));
}

TEST(StringEnumerate__Test, EnumerateFunction) {
    std::string v = "Test string";
    for (auto it : enumerate(v)) {
        ASSERT_EQ(std::get<1>(it), v[std::get<0>(it)]);
        ASSERT_EQ(&std::get<1>(it), &v[std::get<0>(it)]);
    }
    ASSERT_EQ(0, std::get<0>(*enumerate(v).begin()));
    ASSERT_EQ(v[0], std::get<1>(*enumerate(v).begin()));
}

TEST(RvalueEnumerate__Test, EnumerateFunction) {
    for (auto it: enumerate(std::vector<int>(4, 10))) {
        ASSERT_EQ(std::get<1>(it), 10);
    }

    for (auto it: enumerate(range(100))) {
        ASSERT_EQ(std::get<0>(it), std::get<1>(it));
    }
}

TEST(ConstEnumerate__Test, EnumerateFunction) {
    const std::string v = "Test string";
    const auto e = enumerate(v);
    for (auto it : enumerate(v)) {
        ASSERT_EQ(std::get<1>(it), v[std::get<0>(it)]);
        ASSERT_EQ(&std::get<1>(it), &v[std::get<0>(it)]);
    }

    for (const auto it : enumerate(v)) {
        ASSERT_EQ(std::get<1>(it), v[std::get<0>(it)]);
        ASSERT_EQ(&std::get<1>(it), &v[std::get<0>(it)]);
    }
}