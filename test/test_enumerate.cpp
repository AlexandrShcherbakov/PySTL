//
// Created by alex on 14.03.18.
//

#include "gtest/gtest.h"

#include "enumerate.h"
#include "range.h"

using namespace PySTL;

TEST(EnumerateFunction, VectorEnumerate) {
    std::vector<float> v(10, 1e-4f);
    for (auto it : enumerate(v)) {
        ASSERT_EQ(std::get<1>(it), v[std::get<0>(it)]);
        ASSERT_EQ(&std::get<1>(it), &v[std::get<0>(it)]);
    }
    ASSERT_EQ(0, std::get<0>(*enumerate(v).begin()));
    ASSERT_EQ(v[0], std::get<1>(*enumerate(v).begin()));
}


TEST(EnumerateFunction, ArrayEnumerate) {
    std::array<float, 3> v = {1, 2, 3};
    for (auto it : enumerate(v)) {
        ASSERT_EQ(std::get<1>(it), v[std::get<0>(it)]);
        ASSERT_EQ(&std::get<1>(it), &v[std::get<0>(it)]);
    }
    ASSERT_EQ(0, std::get<0>(*enumerate(v).begin()));
    ASSERT_EQ(v[0], std::get<1>(*enumerate(v).begin()));
}

TEST(EnumerateFunction, StringEnumerate) {
    std::string v = "Test string";
    for (auto it : enumerate(v)) {
        ASSERT_EQ(std::get<1>(it), v[std::get<0>(it)]);
        ASSERT_EQ(&std::get<1>(it), &v[std::get<0>(it)]);
    }
    ASSERT_EQ(0, std::get<0>(*enumerate(v).begin()));
    ASSERT_EQ(v[0], std::get<1>(*enumerate(v).begin()));
}

TEST(EnumerateFunction, RvalueEnumerate) {
    for (auto it: enumerate(std::vector<int>(4, 10))) {
        ASSERT_EQ(std::get<1>(it), 10);
    }

    for (auto it: enumerate(range(100))) {
        ASSERT_EQ(std::get<0>(it), std::get<1>(it));
    }
}

TEST(EnumerateFunction, ConstEnumerate) {
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