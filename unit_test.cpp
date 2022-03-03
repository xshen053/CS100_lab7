#include "gtest/gtest.h"

#include "op_test.hpp"
#include "Rand_test.hpp"
#include "mult_test.hpp"

#include "div_test.hpp"
#include "addtest.hpp"
#include "subtest.hpp"
#include "pow_test.hpp"
#include "visitor_test.hpp"
#include "iterator_test.hpp"
#include "math_test.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
