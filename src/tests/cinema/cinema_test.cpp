//#define ENABLE_CINEMA_TEST  // Uncomment this line to enable the Calculator tests

#include "gtest/gtest.h"
#include "../../cinema/header/cinema.h"  // Adjust this include path based on your project structure

using namespace Coruh::Calculator;

class CalculatorTest : public ::testing::Test {
protected:
	void SetUp() override {
		// Setup test data
	}

	void TearDown() override {
		// Clean up test data
	}
};


/**
 * @brief The main function of the test program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return int The exit status of the program.
 */
int main(int argc, char** argv) {
#ifdef ENABLE_CINEMA_TEST
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
#else
	return 0;
#endif
}