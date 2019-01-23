//
// Created by alex on 21.01.2019.
//

#include "gtest/gtest.h"

#include "sum.h"


using namespace PySTL;

TEST(SumFunction, VectorSum) {
    std::vector<int> v(10, 10);
    ASSERT_EQ(sum(v), 100);
    std::vector<float> x(3, 5);
    ASSERT_EQ(sum(x), 15);
    ASSERT_EQ(sum(x, 5.f), 20.f);
}

TEST(SumFunction, StaticArraySum) {
    int a[] = {1, 2, 3};
    ASSERT_EQ(sum(a), 6);
    std::string s[] = {"1", "2", "3"};
    ASSERT_EQ(sum(s, std::string("start")), "start123");
}