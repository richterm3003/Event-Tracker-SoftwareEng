// #include <gtest/gtest.h>
// #include "EventTracker.cpp"



// TEST(DateTest, HandlesBroadInvalidDates) {
//     // Bad month
//     EXPECT_FALSE(validateDate("13", "01", "2026"));
//     EXPECT_FALSE(validateDate("0", "01", "2026"));
//     // Bad day
//     EXPECT_FALSE(validateDate("06", "50", "2026"));
//     EXPECT_FALSE(validateDate("06", "0", "2026"));
    
//     // Bad year
//     EXPECT_FALSE(validateDate("06", "12", "1900"));
//     EXPECT_FALSE(validateDate("06", "12", "3000"));
//     // Good date
//     EXPECT_TRUE(validateDate("06", "12", "2026"));
// }
// TEST(DateTest, HandlesDaysInMonths) {
//     // Months with 31 days
//     for (const std::string& month : months31) {
//         EXPECT_TRUE(validateDate(month, "31", "2026"));
//     }
//     // Months with 30 days
//     for (const std::string& month : months30) {
//         EXPECT_TRUE(validateDate(month, "30", "2026"));
//         EXPECT_FALSE(validateDate(month, "31", "2026"));
//     }
//     // February
//     EXPECT_TRUE(validateDate("02", "28", "2026"));
//     EXPECT_FALSE(validateDate("02", "29", "2026"));
// }

// int main(int argc, char** argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }