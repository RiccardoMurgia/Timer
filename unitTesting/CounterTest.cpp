//
// Created by riccardo on 19/12/20.
//

#include "gtest/gtest.h"
#include "../Counter.h"

Counter *counter = Counter::getInstance();

TEST(CounterTests, increaseTest) {
    QDateTime currentDateTime = QDateTime::currentDateTime();
    ASSERT_EQ(counter->getHours(), currentDateTime.time().hour());
    ASSERT_EQ(counter->getMinutes(), currentDateTime.time().minute());
    ASSERT_NEAR(counter->getSeconds(), currentDateTime.time().second(), 3);
}