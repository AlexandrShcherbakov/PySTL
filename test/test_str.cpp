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
}
