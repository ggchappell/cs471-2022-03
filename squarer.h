// squarer.h
// Glenn G. Chappell
// 2022-10-03
//
// For CS 471 Fall 2022
// Header for class Squarer
// There is no associated source file

#ifndef FILE_SQUARE_H_INCLUDED
#define FILE_SQUARE_H_INCLUDED


// Class Squarer
// Object that squares things. Use member function square.
class Squarer {
public:

    // square
    // Returns the square of its argument.
    template<typename Num>
    Num square(Num x)
    {
        return x*x;
    }
};


#endif  //#ifndef FILE_SQUARE_H_INCLUDED

