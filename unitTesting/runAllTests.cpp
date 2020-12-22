//
// Created by riccardo on 22/11/20.
//

#include "gtest/gtest.h"
#include "../Counter.h"

Counter *Counter::instance = nullptr;

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


