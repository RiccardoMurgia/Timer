//
// Created by riccardo on 22/11/20.
//

#include "gtest/gtest.h"
#include "../Time.h"

TEST(TimeTests, setTimeTest) {
    Time time(0, 0, 0);
    time.setHours(1);
    time.setMinutes(2);
    time.setSeconds(3);
    ASSERT_EQ(1, time.getHours());
    ASSERT_EQ(2, time.getMinutes());
    ASSERT_EQ(3, time.getSeconds());
}

TEST(TimeTests, setFormatTest) {
    Time time(0, 0, 0);
    ASSERT_EQ(Format12h, time.getFormat());
}

TEST(TimeTests, getFullStringTest) {
    Time time(10, 15, 25);
    ASSERT_EQ("10 : 15 : 25 AM", time.getFullString());
    time.setFormat(Format24h);
    ASSERT_EQ("10 : 15 : 25", time.getFullString());
}

TEST(TimeTests, insertAWrongValueTest) {
    Time time(0, 0, 0);
    ASSERT_THROW(time.setHours(25), std::invalid_argument);
    ASSERT_THROW(time.setMinutes(-12), std::invalid_argument);
    ASSERT_THROW(time.setSeconds(70), std::invalid_argument);
}
