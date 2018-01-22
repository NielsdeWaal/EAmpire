#include "gtest/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); ///< Initialize testing
    int ret = RUN_ALL_TESTS(); ///< Run all tests
    return ret;
}
