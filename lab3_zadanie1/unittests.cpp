#include <gtest/gtest.h>
#include "SparseVec.hpp"

TEST(SparseVecTest, ConstructorDefValue) {
    SparseVec vec(5, 0.0);
    EXPECT_EQ(vec[0], 0.0);
    EXPECT_TRUE(vec.is_default(0));
}

TEST(SparseVecTest, SetterGetter) {
    SparseVec vec(5, 0.0);
    vec[2] = 3.5;
    EXPECT_EQ(vec[2], 3.5);
    EXPECT_FALSE(vec.is_default(2));
}

TEST(SparseVecTest, Addition) {
    SparseVec v1(3, 0.0), v2(3, 0.0);
    v1[0] = 1.0;
    v2[0] = 2.0;
    SparseVec v3 = v1 + v2;
    EXPECT_EQ(v3[0], 3.0);
}

TEST(SparseVecTest, Scalar) {
    SparseVec v(3, 0.0);
    v[1] = 4.0;
    SparseVec res = v * 2.0;
    EXPECT_EQ(res[1], 8.0);
}

TEST(SparseVecTest, DotProduct) {
    SparseVec v1(3, 0.0), v2(3, 0.0);
    v1[0] = 2.0;
    v2[0] = 3.0;
    EXPECT_EQ(v1 * v2, 6.0);
}

TEST(SparseVecTest, LenCalculate) {
    SparseVec v(2, 0.0);
    v[0] = 3.0;
    v[1] = 4.0;
    EXPECT_DOUBLE_EQ(v.length(), 5.0);
}

TEST(SparseVecTest, ParallelTrue) {
    SparseVec v1(3, 0.0), v2(3, 0.0);
    v1[0] = 1.0; v1[1] = 2.0;
    v2[0] = 2.0; v2[1] = 4.0;
    EXPECT_TRUE(v1.is_parallel(v2));
}

TEST(SparseVecTest, ParallelFalse) {
    SparseVec v1(3, 0.0), v2(3, 0.0);
    v1[0] = 1.0; v1[1] = 2.0;
    v2[0] = 2.0; v2[1] = 3.0;
    EXPECT_FALSE(v1.is_parallel(v2));
}

TEST(SparseVecTest, ComparisonOperators) {
    SparseVec v1(2, 0.0), v2(2, 0.0);
    v1[0] = 1.0;
    v2[0] = 2.0;
    EXPECT_TRUE(v1 < v2);
    EXPECT_TRUE(v2 > v1);
    SparseVec v3 = v1 * 2.0;
    EXPECT_TRUE(v3 == v2);
}

TEST(SparseVecTest, StreamIO) {
    SparseVec v1(3, 0.0);
    v1[0] = 1.0; v1[2] = 5.0;

    std::stringstream ss;
    ss << v1;

    SparseVec v2(1, 0.0);
    ss >> v2;

    EXPECT_EQ(v2[0], 1.0);
    EXPECT_EQ(v2[2], 5.0);
}

TEST(SparseVecTest, ProxyTest) {
    SparseVec v1(4, 0.0);
    v1[1] = 3.0;

    SparseVec v2 = v1; // copy constructor
    EXPECT_EQ(v2[1], 3.0);

    SparseVec v3(4, 0.0);
    v3 = v1; // assignment operator
    EXPECT_EQ(v3[1], 3.0);
}

TEST(SparseVecTest, OutOfRangeAccess) {
    SparseVec v(2, 0.0);
    EXPECT_THROW(v[2], std::out_of_range);
    EXPECT_THROW(v[100], std::out_of_range);
}

TEST(SparseVecTest, InvalidAddition) {
    SparseVec v1(3, 0.0);
    SparseVec v2(4, 0.0);
    EXPECT_THROW(v1 + v2, std::invalid_argument);
}

TEST(SparseVecTest, InvalidDotProduct) {
    SparseVec v1(2, 0.0);
    SparseVec v2(3, 0.0);
    EXPECT_THROW(v1 * v2, std::invalid_argument);
}

TEST(SparseVecTest, AdditionElliminateDef) {
    SparseVec v1(3, 0.0);
    SparseVec v2(3, 0.0);
    v1[0] = 2.0;
    v2[0] = -2.0;
    SparseVec v3 = v1 + v2;
    EXPECT_TRUE(v3.is_default(0));
}

TEST(SparseVecTest, NonZeroDefault) {
    SparseVec v(3, 1.0);
    EXPECT_EQ(v[2], 1.0);
    v[2] = 1.0;
    EXPECT_TRUE(v.is_default(2));
}

TEST(SparseVecTest, InvalidIndexOnInput) {
    std::stringstream ss("3 0.0 1\n5 1.0\n");
    SparseVec v(3, 0.0);
    EXPECT_THROW(ss >> v, std::invalid_argument);
}

TEST(SparseVecTest, InvalidInputLength) {
    SparseVec v(0, 0.0);
    EXPECT_EQ(v.length(), 0.0);
    EXPECT_THROW(v[0], std::out_of_range);
}
