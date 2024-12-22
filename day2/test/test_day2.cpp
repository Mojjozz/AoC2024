#include <gtest/gtest.h>
#include "RedNosedReports.h"

TEST(RedNosedReportTests, processLevelTestOK) {
    //Given
    std::vector<int> exampleLevel = {1,3,5,6};

    //When
    int result = processReport(exampleLevel);

    //Then
    ASSERT_EQ(0, result);
}


TEST(RedNosedReportTests, processLevelTestNok) {
    //Given
    std::vector<int> exampleLevelNok = {1, 5, 6, 7};

    //When
    int result = processReport(exampleLevelNok);

    //Then
    ASSERT_EQ(-1, result);
}