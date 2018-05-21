//
// Created by alex on 15.03.18.
//

#include "gtest/gtest.h"

#include "../include/PySTL_functions/len.h"


using namespace PySTL;

TEST(VectorLen__Test, LenFunction) {
    std::vector<int> v(10, 10);
    ASSERT_EQ(v.size(), len(v));
    v.clear();
    ASSERT_EQ(v.size(), len(v));
    std::vector<char> z(100, 'a');
    ASSERT_EQ(z.size(), len(z));
}

TEST(ArrayLen__Test, LenFunction) {
    std::array<int, 100> v = {0};
    ASSERT_EQ(v.size(), len(v));
}


TEST(MapLen__Test, LenFunction) {
    std::map<int, float> v;
    v[0] = 1e-5f;
    v[-1000] = 200;
    ASSERT_EQ(v.size(), len(v));
}


TEST(StringLen__Test, LenFunction) {
    std::string v = "asdasdad";
    ASSERT_EQ(v.size(), len(v));
}
