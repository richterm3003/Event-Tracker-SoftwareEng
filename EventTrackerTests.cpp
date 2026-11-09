#include <gtest/gtest.h>
#include "EventTracker.h"

TEST(DateTest, HandlesCorrectDates) {
    //Bad Month
    EXPECT_EQ(validateDate(13, 01, 2026), false);
    EXPECT_EQ(validateDate(0, 01, 2026), false);
    //Bad Day
    EXPECT_EQ(validateDate(06, 50, 2026), false);
    EXPECT_EQ(validateDate(06, 0, 2026), false);
    //Bad Year
    EXPECT_EQ(validateDate(06, 12, 1900), false);
    EXPECT_EQ(validateDate(06, 12, 3000), false);
    //Good Date
    EXPECT_EQ(validateDate(06, 12, 2026), true);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}