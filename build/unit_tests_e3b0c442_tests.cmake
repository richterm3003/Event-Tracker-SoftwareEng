add_test([=[DateTest.HandlesBroadInvalidDates]=]  [==[C:/Algorithms Class/Sudoku/Event-Tracker-SoftwareEng/build/unit_tests.exe]==] [==[--gtest_filter=DateTest.HandlesBroadInvalidDates]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DateTest.HandlesBroadInvalidDates]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Algorithms Class\Sudoku\Event-Tracker-SoftwareEng\EventTrackerTests.cpp:6]==]
    WORKING_DIRECTORY [==[C:/Algorithms Class/Sudoku/Event-Tracker-SoftwareEng/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[DateTest.HandlesDaysInMonths]=]  [==[C:/Algorithms Class/Sudoku/Event-Tracker-SoftwareEng/build/unit_tests.exe]==] [==[--gtest_filter=DateTest.HandlesDaysInMonths]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DateTest.HandlesDaysInMonths]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Algorithms Class\Sudoku\Event-Tracker-SoftwareEng\EventTrackerTests.cpp:20]==]
    WORKING_DIRECTORY [==[C:/Algorithms Class/Sudoku/Event-Tracker-SoftwareEng/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(unit_tests_TESTS [==[DateTest.HandlesBroadInvalidDates]==] [==[DateTest.HandlesDaysInMonths]==])
