//
// Created by alex on 20.05.2018.
//

#include "gtest/gtest.h"

#include "zip.h"

using namespace PySTL;

TEST(ZipFunction, OneArgZip) {
    std::vector<int> a(10, 5);
    for (const auto [i] : zip(a)) {
        ASSERT_EQ(i, 5);
    }
}

TEST(ZipFunction, TwoArgZip) {
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    for (const auto [i, j] : zip(a, a)) {
        ASSERT_EQ(i, j);
    }
}
