//
// Created by alex on 16.03.18.
//

#include "gtest/gtest.h"

#include "../include/PySTL_functions/range.h"

using namespace PySTL;

TEST(RangeToEnd__Test, RangeFunction) {
    for (auto x: range(10)) {
        ASSERT_LT(x, 10);
        ASSERT_GE(x, 0);
    }
}

TEST(RangeBeginToEnd__Test, RangeFunction) {
    for (auto x: range(10, 20)) {
        ASSERT_LT(x, 20);
        ASSERT_GE(x, 10);
    }
}

TEST(RangeBeginToEndWithStep__Test, RangeFunction) {
    int count = 0;
    for (auto x: range(10, 20, 2)) {
        ASSERT_LT(x, 20);
        ASSERT_GE(x, 10);
        count++;
    }
    ASSERT_EQ(count, 5);

    count = 0;
    for (auto x: range(10, 20, 3)) {
        ASSERT_LT(x, 20);
        ASSERT_GE(x, 10);
        ASSERT_TRUE(x % 3 == 1);
        count++;
    }
    ASSERT_EQ(count, 4);
}
