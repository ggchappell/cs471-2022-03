// pps_test.cpp
// Glenn G. Chappell
// 2022-10-12
//
// For CS 471 Fall 2022
// Test suite for pretty_print_square
// Uses doctest unit-testing framework
// Requires doctest.h, pps.h, pps.cpp

// Includes for code to be tested
#include "pps.h"             // For pretty_print_square
#include "pps.h"             // Double-inclusion check, for testing only

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
                             // doctest writes main for us
#include "doctest.h"         // For doctest

#include <sstream>
using std::ostringstream;
#include <string>
using std::string;


TEST_CASE("pretty_print_square works")
{
    ostringstream os;

    SUBCASE("p_p_s w/ 5")
    {
        int num = 5;
        string expected = "******\n*    *\n* 25 *\n*    *\n******\n";
        pretty_print_square(num, os);
        auto result = os.str();
        CHECK(result == expected);
    }

    SUBCASE("p_p_s w/ -1")
    {
        int num = -1;
        string expected = "*****\n*   *\n* 1 *\n*   *\n*****\n";
        pretty_print_square(num, os);
        auto result = os.str();
        CHECK(result == expected);
    }
}

