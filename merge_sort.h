// merge_sort.h
// Glenn G. Chappell
// 2022-11-21
//
// Merge Sort (Recursive)
// There is no associated source file.

#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;
#include <algorithm>
using std::move;
#include <iterator>
using std::begin;
using std::end;
using std::distance;
using std::advance;
using std::iterator_traits;


// stableMerge
// Merge two halves of a sequence, each sorted, into a single sorted
// sequence in the same location. Merge is done in a stable manner.
// Requirements on Types:
//     FDIter is a forward iterator type.
//     The value type of FDIter has default ctor, dctor, copy=,
//      operator<.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, middle) and [middle, last) are valid ranges, each sorted
//      by <.
template <typename FDIter>
void stableMerge(FDIter first, FDIter middle, FDIter last)
{
    // Get type of what iterators point to
    using Value = typename iterator_traits<FDIter>::value_type;

    vector<Value> buffer(distance(first, last));
                               // Buffer for temporary copy of data
    auto in1 = first;          // Read location in 1st half
    auto in2 = middle;         // Read location in 2nd half
    auto out = begin(buffer);  // Write location in buffer

    // Merge two sorted lists into a single list in buff.
    while (in1 != middle && in2 != last)
    {
        if (*in2 < *in1)  // Must do comparison this way, to be stable.
            *out++ = *in2++;
        else
            *out++ = *in1++;
    }

    // Move remainder of original sequence to buffer.
    // Only one of the following two calls will do anything, since the
    //  other is given an empty source range.
    // NOTE. This is std::move from <algorithm>, not from <utility>!
    move(in1, middle, out);
    move(in2, last, out);

    // Move buffer contents back to original sequence location.
    move(begin(buffer), end(buffer), first);
}




// mergeSort
// Sort a range using Merge Sort.
// Recursive.
// Requirements on Types:
//     FDIter is a forward iterator type.
//     The value type of FDIter has default ctor, dctor, copy=,
//      operator<.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, last) is a valid range.
template <typename FDIter>
void mergeSort(FDIter first, FDIter last)
{
    // Compute size of range
    size_t size = distance(first, last);

    // BASE CASE
    if (size <= 1)
        return;

    // RECURSIVE CASE
    auto middle = first;
    advance(middle, size/2);  // middle is iterator to middle of range

    // Recursively sort the two lists
    mergeSort(first, middle);
    mergeSort(middle, last);

    // And merge them
    stableMerge(first, middle, last);
}

