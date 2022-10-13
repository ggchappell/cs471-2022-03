// pps.h
// Glenn G. Chappell
// 2022-10-12
//
// For CS 471 Fall 2022
// Header for function pretty_print_square

#ifndef FILE_PPS_H_INCLUDED
#define FILE_PPS_H_INCLUDED

#include <iostream>  // For std::ostream, std::cout


// pretty_print_square
// Print n surrounded by a box of asterisks to the given ostream, which
// defaults to cout.
void pretty_print_square(int n,
                         std::ostream & outstr = std::cout);

#endif  ///#ifndef FILE_PPS_H_INCLUDED

