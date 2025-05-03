#include <gtest/gtest.h>
#include "vec_n.hpp"
#include <limits>

// Default contructor test
TEST(VecNTest, DefaultConstructor) {
    vec_n v(3);
    EXPECT_EQ(v.size(), 3);
}

// Constructor test with values
TEST(VecNTest, ValueConstructor) {
    std::vector<double> values = {1.0, 2.0, 3.0};
    vec_n v(values);
    EXPECT_EQ(v.size(), 3);
    EXPECT_DOUBLE_EQ(v.get_element(0), 1.0);
    EXPECT_DOUBLE_EQ(v.get_element(1), 2.0);
    EXPECT_DOUBLE_EQ(v.get_element(2), 3.0);
}

// Addition operation test
TEST(VecNTest, AdditionOperator) {
    vec_n v1({1.0, 2.0, 3.0});
    vec_n v2({4.0, 5.0, 6.0});
    vec_n result = v1 + v2;
    EXPECT_DOUBLE_EQ(result.get_element(0), 5.0);
    EXPECT_DOUBLE_EQ(result.get_element(1), 7.0);
    EXPECT_DOUBLE_EQ(result.get_element(2), 9.0);
}

// Dot product test
TEST(VecNTest, DotProduct) {
    vec_n v1({1.0, 2.0, 3.0});
    vec_n v2({4.0, 5.0, 6.0});
    double dot = v1 * v2;
    EXPECT_DOUBLE_EQ(dot, 32.0);
}

// Exception for adding different sized vectors
TEST(VecNTest, AdditionDifferentSizesThrows) {
    vec_n v1({1.0, 2.0});
    vec_n v2({1.0, 2.0, 3.0});
    EXPECT_THROW(v1 + v2, std::invalid_argument);
}

// Test for out of range element access
TEST(VecNTest, OutOfRangeElementAccess) {
    vec_n v({1.0, 2.0, 3.0});
    EXPECT_THROW(v.get_element(5), std::out_of_range);
}

// Not fully defined vector
TEST(VecNTest, NotFullyDefinedVec) {
    vec_n v1(2);
    vec_n v2({1.0, 2.0});
    EXPECT_THROW(v1 + v2, std::invalid_argument);
}

// Comparing vector length, all cases
TEST(VecNTest, CompareOperator) {
    vec_n v1({1.0, 2.0}); // length is sqrt(5) < 5
    vec_n v2({3.0, 4.0}); // length is sqrt(9+16) = 5
    vec_n v3({3.0, 4.0});
    EXPECT_EQ(v1.compare(v2), 1); // second vector is longer, so, should return 1
    EXPECT_EQ(v2.compare(v1), -1);
    EXPECT_EQ(v2.compare(v3), 0);
}

// Calculating vector length
TEST(VecNTest, CalculateLength) {
    vec_n v1({3.0, 4.0}); // length is sqrt(9+16) = 5
    vec_n v2({3.0, -4.0});
    EXPECT_DOUBLE_EQ(v1.length(), 5.0);
    EXPECT_DOUBLE_EQ(v2.length(), 5.0);

}

// Read and Load from file tests
TEST(VecNTest, SaveAndLoadFromFile) {
    std::string filename = "test_vector.txt";
    vec_n v1({1.0, 2.0, 3.0});
    v1.saveToFile(filename);

    vec_n v2 = vec_n::loadFromFile(filename);
    EXPECT_EQ(v2.size(), 3);
    EXPECT_DOUBLE_EQ(v2.get_element(0), 1.0);
    EXPECT_DOUBLE_EQ(v2.get_element(1), 2.0);
    EXPECT_DOUBLE_EQ(v2.get_element(2), 3.0);

    std::remove(filename.c_str()); // Cleaning after use
}

// Test for reading from non existent file
TEST(VecNTest, LoadFromNonExistentFileThrows) {
    EXPECT_THROW(vec_n::loadFromFile("non_existent_file.txt"), std::runtime_error);
}