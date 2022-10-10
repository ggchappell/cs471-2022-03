// squarer_test.cpp
// Glenn G. Chappell
// 2022-10-03
//
// For CS 471 Fall 2022
// Test suite for class Squarer
// Uses doctest unit-testing framework
// Requires doctest.h, squarer.h

// Includes for code to be tested
#include "squarer.h"         // For class Squarer
#include "squarer.h"         // Double-inclusion check, for testing only

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
                             // doctest writes main for us
#include "doctest.h"         // For doctest


TEST_CASE("Class squarer works")
{
    Squarer s;  // Object that squares things

    SUBCASE("Member func square handles non-negative integers")
    {
        CHECK(s.square(0) == 0);
        CHECK(s.square(2) == 4);
        CHECK(s.square(100) == 10000);
        CHECK(s.square(111) == 12321);
    }

    SUBCASE("Member func square handles negative integers")
    {
        CHECK(s.square(-1) == 1);
        CHECK(s.square(-10) == 100);
        CHECK_FALSE(s.square(-1234) < 0);
    }

    SUBCASE("Member func square handles non-integers")
    {
        CHECK(s.square(1.2) == 1.44);
        CHECK(s.square(2.5) == 6.25);
    }
}

