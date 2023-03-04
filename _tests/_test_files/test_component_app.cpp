#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

//------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/app/app_include_test/app_include_test.h"
#include "../../includes/component/component_include_test/component_include_test.h"

//------------------------------------------------------------------------------

using namespace std;



bool test_includes(bool debug=false)
{
  return component_include_test() && app_include_test();
}


//Lord help me! 
const bool debug = false;

TEST(INCLUDE_TEST, IncludeTest)
{
  bool success = test_includes(debug);
  EXPECT_EQ(success, true);
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}