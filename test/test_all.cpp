//
// Created by alex on 24.03.2019.
//

#include "gtest/gtest.h"

#include "all.h"


using namespace PySTL;

TEST(AllTest, AllNone) {
    ASSERT_EQ(all(std::vector<int>()), true) << "Empty iterable must return true";
}

TEST(AllTest, AllBools) {
    const bool iter1[] = {true, true, true};
    ASSERT_EQ(all(iter1), true);

    const std::vector<bool> iter2 = {true, true, true, false};
    ASSERT_EQ(all(iter2), false);
}

TEST(AllTest, AllInts) {
    const int iter1[] = {1, 2, 3};
    ASSERT_EQ(all(iter1), true);

    const std::array<int, 4> iter2 = {1, 0, 1, 2};
    ASSERT_EQ(all(iter2), false);
}

TEST(AllTest, CustomType) {
    struct NewType1 {
        explicit operator bool() const {
            return true;
        };
    };

    struct NewType2 {
        bool operator !() const {
            return true;
        };
    };

    const NewType1 iter1[3];
    ASSERT_EQ(all(iter1), true);

    const std::array<NewType2, 4> iter2;
    ASSERT_EQ(all(iter2), false);
}
