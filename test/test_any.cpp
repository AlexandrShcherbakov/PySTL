//
// Created by alex on 02.04.2019.
//

#include "gtest/gtest.h"

#include "any.h"


using namespace PySTL;

TEST(AnyTest, AnyNone) {
    ASSERT_EQ(any(std::vector<int>()), false) << "Empty iterable must return true";
}

TEST(AnyTest, AnyBools) {
    const bool iter1[] = {false, false, false};
    ASSERT_EQ(any(iter1), false);

    const std::vector<bool> iter2 = {false, false, false, true};
    ASSERT_EQ(any(iter2), true);
}

TEST(AnyTest, AnyInts) {
    const int iter1[] = {0, 0, 0};
    ASSERT_EQ(any(iter1), false);

    const std::array<int, 4> iter2 = {1, 0, 1, 2};
    ASSERT_EQ(any(iter2), true);
}

TEST(AnyTest, CustomType) {
    struct NewType1 {
        explicit operator bool() const {
            return false;
        };
    };

    struct NewType2 {
        explicit operator bool() const {
            return true;
        };
    };

    const NewType1 iter1[3];
    ASSERT_EQ(any(iter1), false);

    const std::array<NewType2, 4> iter2;
    ASSERT_EQ(any(iter2), true);
}
