// pps.cpp
// Glenn G. Chappell
// Started: 2022-10-12
// Updated: 2022-10-17
//
// For CS 471 Fall 2022
// Source for function pretty_print_square

#include "pps.h"     // Our header
#include <ostream>
using std::ostream;
#include <string>
using std::string;
using std::to_string;


// class Squarer
// Has member func "compute", that returns the square of its argument.
//
// Conforms to the interface for a "computer" used by prettify_it.
class Squarer {
public:
    int compute(int n) const
    {
        return n*n;
    }
};


// class Boxer
// Has member func "stringify", that returns a multiline string,
// terminated with a newline, that shows the argument surrounded by a
// box of asterisks.
//
// Conforms to the interface for a "stringifier" used by prettify_it.
class Boxer {
public:
    string stringify(int nn) const
    {
        string nnstr = to_string(nn);
        int nnlen = int(nnstr.size());
        string asters(nnlen+4, '*');
        string blanks(nnlen+2, ' ');
        string nl = "\n";

        string result = asters + nl
                      + "*" + blanks + "*" + nl
                      + "* " + nnstr + " *" + nl
                      + "*" + blanks + "*" + nl
                      + asters + nl;

        return result;
    }
};


// pretty_print_square
// Print n surrounded by a box of asterisks to the given ostream, which
// defaults to cout.
void pretty_print_square(int n,
                         ostream & outstr)  // = cout
{
    string str = prettify_it(n, Squarer(), Boxer());
    outstr << str;
}

