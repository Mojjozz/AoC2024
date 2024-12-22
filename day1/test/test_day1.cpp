#include <gtest/gtest.h>
#include "HistorianHistory.h"
#include <vector>

class Day1Tests : public ::testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>>> {
protected:
    std::vector<int> column1;
    std::vector<int> column2;
    // This runs before each test and will sort the vectors
    void SetUp() override {
    column1 = std::get<0>(GetParam());
    column2 = std::get<1>(GetParam());
    std::sort(column1.begin(), column1.end());
    std::sort(column2.begin(), column2.end());

    }

};

TEST_P(Day1Tests,FirstPuzzleTest) {
    // Capture the output sent to std::cout
    testing::internal::CaptureStdout();

    // call the function
    firstPuzzle(column1, column2);
    
    // Retreive the captured output
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, "Distance: 2\n");

}

TEST_P(Day1Tests,SecondPuzzleTest) {
    // Capture the output sent to std::cout
    testing::internal::CaptureStdout();

    // call the function
    secondPuzzle(column1, column2);

    // Retreive the captured output
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, "score: 1\n");

}

INSTANTIATE_TEST_SUITE_P(
    prefix,
    Day1Tests,
    ::testing::Values(
        std::make_tuple(std::vector<int>{5,3,1}, std::vector<int>{6,1,2})
    )
);