//
// Created by alex on 07.07.2018.
//

#include "gtest/gtest.h"

#include <str.h>

using namespace PySTL;

TEST(StrTest, Split) {
    const str s("w1 w2  w3");
    const auto split = s.split();
    ASSERT_EQ(split.size(), 3);
    ASSERT_EQ(split[0], str("w1"));
    ASSERT_EQ(split[1], str("w2"));
    ASSERT_EQ(split[2], str("w3"));

    const str s1("asd123asd");
    ASSERT_EQ(s1, s1.split()[0]);

    const auto split1 = s.split(1);
    ASSERT_EQ(split1.size(), 2);
    ASSERT_EQ(split1[0], str("w1"));
    ASSERT_EQ(split1[1], str("w2  w3"));

    const auto split2 = s.split("w");
    ASSERT_EQ(split2.size(), 4);
    ASSERT_EQ(split2[0], str(""));
    ASSERT_EQ(split2[1], str("1 "));
    ASSERT_EQ(split2[2], str("2  "));
    ASSERT_EQ(split2[3], str("3"));
}
