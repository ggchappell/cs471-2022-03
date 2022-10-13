// pps_main
// Glenn G. Chappell
// 2022-10-12
// Simple main program for pretty_print_square

#include "pps.h"
#include <iostream>
using std::cout;


// Main Program
//  Calls function pretty_print_square.
int main()
{
    int num = 638;
    cout << "The square of " << num << ":" << "\n";
    pretty_print_square(num);
}

