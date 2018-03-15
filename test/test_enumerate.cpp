//
// Created by alex on 14.03.18.
//

#include "gtest/gtest.h"

#include "../include/PySTL.h"

TEST(VectorEnumerate__Test, EnumerateFunction) {
    std::vector<float> v(10, 1e-4f);
    for (auto it : PySTL::enumerate(v)) {
        ASSERT_EQ(std::get<1>(it), v[std::get<0>(it)]);
    }
    ASSERT_EQ(0, std::get<0>(*PySTL::enumerate(v).begin()));
    ASSERT_EQ(v[0], std::get<1>(*PySTL::enumerate(v).begin()));
}


TEST(ArrayEnumerate__Test, EnumerateFunction) {
    std::array<float, 3> v = {1, 2, 3};
    for (auto it : PySTL::enumerate(v)) {
        ASSERT_EQ(std::get<1>(it), v[std::get<0>(it)]);
    }
    ASSERT_EQ(0, std::get<0>(*PySTL::enumerate(v).begin()));
    ASSERT_EQ(v[0], std::get<1>(*PySTL::enumerate(v).begin()));
}

TEST(StringEnumerate__Test, EnumerateFunction) {
    std::string v = "Test string";
    for (auto it : PySTL::enumerate(v)) {
        ASSERT_EQ(std::get<1>(it), v[std::get<0>(it)]);
    }
    ASSERT_EQ(0, std::get<0>(*PySTL::enumerate(v).begin()));
    ASSERT_EQ(v[0], std::get<1>(*PySTL::enumerate(v).begin()));
}
