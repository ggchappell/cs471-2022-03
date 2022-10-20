// pps.h
// Glenn G. Chappell
// Started: 2022-10-12
// Updated: 2022-10-19
//
// For CS 471 Fall 2022
// Header for function pretty_print_square

#ifndef FILE_PPS_H_INCLUDED
#define FILE_PPS_H_INCLUDED

#include <iostream>  // For std::ostream, std::cout
#include <string>    // For std::string


// pretty_print_square
// Print n surrounded by a box of asterisks to the given ostream, which
// defaults to cout.
void pretty_print_square(int n,
                         std::ostream & outstr = std::cout);


// prettify_it
// Given a "computer" object (has member "compute" that takes int and
// returns int) and "stringifier" object (has member "stringify that
// takes string and returns string), returns the composition of the two
// operations: compute, then stringify.
template<typename Compute, typename Stringify>
std::string prettify_it(int n,
                        Compute && computer,  // Universal reference
                        Stringify && stringifier)
{
    int nn = computer.compute(n);
    std::string str = stringifier.stringify(nn);
    return str;
}


// class Cuber
// Compute class. Function compute returns the cube of its argument.
//
// Conforms to the interface for a "computer" used by prettify_it.
class Cuber {
public:
    int compute(int n)
    {
        return n*n*n;
    }
};


#endif  //#ifndef FILE_PPS_H_INCLUDED

