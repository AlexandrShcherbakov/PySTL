//
// Created by alex on 15.03.18.
//

#include "gtest/gtest.h"

#include "len.h"


using namespace PySTL;

TEST(LenFunction, VectorLen) {
    std::vector<int> v(10, 10);
    ASSERT_EQ(v.size(), len(v));
    v.clear();
    ASSERT_EQ(v.size(), len(v));
    std::vector<char> z(100, 'a');
    ASSERT_EQ(z.size(), len(z));
}

TEST(LenFunction, ArrayLen) {
    std::array<int, 100> v = {0};
    ASSERT_EQ(v.size(), len(v));
}


TEST(LenFunction, MapLen) {
    std::map<int, float> v;
    v[0] = 1e-5f;
    v[-1000] = 200;
    ASSERT_EQ(v.size(), len(v));
}


TEST(LenFunction, StringLen) {
    std::string v = "asdasdad";
    ASSERT_EQ(v.size(), len(v));
}
