#include <algorithm>
#include <iostream>
#include <type_traits>

/**
 * 3. Run Length Encoding
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(std::is_same_v<RLE<0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1>::type, Vector<5,0,2,1,12,0,1,1>>);
// static_assert(std::is_same_v<RLE<1,1,1,1,9,9,9,2>::type, Vector<4,1,3,9,1,2>>);


/**
 * 4. Minimum Subset Sum Difference
 *    Given a set of numbers, consider partitioning them into two sets, summing each to receive two numbers.
 *    Find the absolute difference between these two numbers that is the smallest (over all possible partitions).
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(MSSD<>::value == 0);
// static_assert(MSSD<1>::value == 1);
// static_assert(MSSD<1, 1>::value == 0);
// static_assert(MSSD<1, 1, 1>::value == 1);
// static_assert(MSSD<20, 30, 10, 10, 20>::value == 10);
// static_assert(MSSD<5, 20, 25, 10, 10, 20>::value == 0);
// static_assert(MSSD<5, 10, 15, 20, 25, 10, 10, 20>::value == 5);


/**
 * 5. Define type Middle to contain the middle letter of a string with an odd length.
 *
 * We'll need a type level string container (requires C++20).
 * This is a warmup before the next exercise.
 */
template<size_t N>
struct MetaString {
    constexpr MetaString(const char (&s)[N])
    {
        std::copy_n(s, N, value);
    }

    char value[N];
    std::size_t size = N;
};

template<MetaString S>
struct Middle
{
// Your code goes here:
// ^ Your code goes here
};

// static_assert(Middle<"abc">::value == 'b');
// static_assert(Middle<"abcde">::value == 'c');

/**
 * 6. Define DeletesToEqual which calculates the minimum number of letters to delete from two strings to make
 * them equal.
 *
 * (This is a simplification of the well-known edit distance problem.)
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(DeletesToEqual<"a", "b">::value == 2);
// static_assert(DeletesToEqual<"abc", "bcd">::value == 2);
// static_assert(DeletesToEqual<"abcd", "bcd">::value == 1);
// static_assert(DeletesToEqual<"abc", "xbz">::value == 4);
// static_assert(DeletesToEqual<"ababa", "bb">::value == 3);
// static_assert(DeletesToEqual<"chocolatefactory", "charlie">::value == 15);
