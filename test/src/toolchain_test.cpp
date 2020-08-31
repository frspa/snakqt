#include <gmock/gmock.h>
#include <QTest>

namespace  {

TEST(ToolchainTest,
     GIVEN_tollchain_WHEN_test_is_started_THEN_test_toolchain_is_set_up_correctly){

  // setup
  const bool firstVariable = true;
  const bool secondVariable = true;

  // test
  bool result = false;
  if (firstVariable == secondVariable){
      result = true;
    }

  // verification
  EXPECT_TRUE(result);

}

} //namespace
