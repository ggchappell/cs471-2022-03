// pps_test.cpp
// Glenn G. Chappell
// Started: 2022-10-12
// Updated: 2022-01-19
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
using std::to_string;
#include <algorithm>
using std::reverse;
#include <iterator>
using std::begin;
using std::end;


// class ComputeMock
// Do-nothing Compute class. Function compute returns its argument.
//
// Conforms to the interface for a "computer" used by prettify_it.
class ComputeMock {
public:
    int compute(int n) const
    {
        return n;
    }
};


// class StringifyMock
// Do-nothing Stringify class. Function stringify returns the string
// form of its argument.
//
// Conforms to the interface for a "stringifier" used by prettify_it.
class StringifyMock {
public:
    string stringify(int nn) const
    {
        return to_string(nn);
    }
};


// class Doubler
// Has member func "compute", that returns twice its argument.
//
// Conforms to the interface for a "computer" used by prettify_it.
class Doubler {
public:
    int compute(int n) const
    {
        return 2*n;
    }
};


// class Reverser
// Has member func "stringify" that converts a number to a string and
// returns the reverse of that string.
//
// Conforms to the interface for a "stringifier" used by prettify_it.
class Reverser {
public:
    string stringify(int nn) const
    {
        auto ss = to_string(nn);
        reverse(begin(ss), end(ss));
        return ss;
    }
};


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


TEST_CASE("prettify_it does computation correctly")
{
    SUBCASE("p_i w/ doubling")
    {
        int num = 6;
        string expected = "12";
        auto result = prettify_it(num, Doubler(), StringifyMock());
        CHECK(result == expected);
    }
}


TEST_CASE("prettify_it does stringification correctly")
{
    SUBCASE("p_i w/ reversing")
    {
        int num = 12345678;
        string expected = "87654321";
        auto result = prettify_it(num, ComputeMock(), Reverser());
        CHECK(result == expected);
    }
}


TEST_CASE("Cuber works")
{
    SUBCASE("Try Cuber by itself & with prettify_it")
    {
        // ------------------------------------------------------------

        // ARRANGE

        Cuber c;

        int n1 = 3;
        int expected1 = 27;

        // ACT

        auto result1 = c.compute(n1);

        // ASSERT

        REQUIRE(result1 == expected1);
            // We do REQUIRE here, rather than CHECK, because if Cuber
            // does not work by itself, then there is not much point in
            // testing it as used by prettify_it (below).

        // ------------------------------------------------------------

        int n2 = 6;
        string expected2 = "216";
        auto result2 = prettify_it(n2, c, StringifyMock());
        CHECK(result2 == expected2);
    }

}

