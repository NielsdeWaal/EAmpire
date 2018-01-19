#include <cmath>
#include <gtest/gtest.h>

/**
 * @brief Template for the test framework.
 *
 * This template can also be used to test running the framework itself.
 */
namespace { ///< Namespace to keep everything together.

TEST(TestTesting, math_exp_normal) { 
    EXPECT_EQ(16, std::exp2(4)); 
}

TEST(TestTesting, Exception) {
    try {
        throw 42;
        FAIL() << "Expected exception";
    } catch (int i) { 
        EXPECT_EQ(42, i);
    } catch (...) {
        FAIL() << "Incorrect exception given";
    }
}

}
