//
// Created by riccardo on 23/11/20.
//
#include "gtest/gtest.h"
#include "../Date.h"


TEST(DataTests, setDataTest) {
    Date date(31, 1, 1957, 0, false);
    date.setDay(3);
    date.setMonth(3);
    date.setYear(1956);
    date.setDayOfWeek(2);
    date.setLeapWeek(true);
    date.setFormat("dd - mm - yyyy");
    ASSERT_EQ(3, date.getDay());
    ASSERT_EQ(3, date.getMonth());
    ASSERT_EQ(1956, date.getYear());
    ASSERT_EQ(2,date.getDayOfWeek());
    ASSERT_TRUE(date.isLeapYear());
    ASSERT_EQ("dd - mm - yyyy",date.getFormat());
}


TEST(DataTests, insertAWrongValueTest) {
    Date date(31, 1, 1957, 0, false);
    date.setDay(32);
    date.setMonth(0);
    date.setYear(-3);
    ASSERT_EQ(1,date.getDay());
    ASSERT_EQ(1,date.getMonth());
    ASSERT_EQ(0,date.getYear());
}

TEST (Datetast, checkIfIsALeapYeartest) {
    Date dateInNoLeapYear(31, 1, 1957, 0, false);
    Date dateInLeapYear(3, 3, 1956, 0 , true);
    ASSERT_FALSE(dateInNoLeapYear.checkIfIsALeapYear(1957));
    ASSERT_TRUE(dateInLeapYear.checkIfIsALeapYear(1956));
}

TEST(DateTest, getFullStringTest){
    Date dateA(31, 1, 1957, 0, false,"DD-MM-YYYY");
    Date dateB(3, 3, 1956, 0 , true,"DD-MM-YY");
    Date dateC(4,4,2017,2,false);
    ASSERT_EQ("31 - 01 - 1957",dateA.getFullString());
    ASSERT_EQ("03 - 03 - 56", dateB.getFullString());
    ASSERT_EQ("Tuesday, 04 - 04 - 2017", dateC.getFullString());
}
