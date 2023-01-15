#include "gtest/gtest.h"
#include "../src/manager.cpp"
#include "task_tests.hpp"
#include "iter_tests.hpp"

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
