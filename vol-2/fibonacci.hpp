/**
 * 1. Define Fibonacci to contain the n-th number in the series
 * 0,1,1,2,3,5,8,13,...
 *
 * Try three implementations:
 * - Using templated structs (hint: use the SFINAE Enable trick).
 * - Recursive constexpr function.
 * - Iterative constexpr function.
 *
 * Measure the compilation time of each implementation. Observe how the
 * templated-structs implementation is a direct implementation of the recursive
 * definition of Fibonacci sequence, yet it's as fast as the iterative
 * implementation thanks to memoization built into the template system.
 */

template<int I>
struct Fibonacci
{
  static constexpr int value =
    Fibonacci<I - 1>::value + Fibonacci<I - 2>::value;
};

template<>
struct Fibonacci<0>
{
  static constexpr int value = 0;
};

template<>
struct Fibonacci<1>
{
  static constexpr int value = 1;
};

static_assert(Fibonacci<0>::value == 0);
static_assert(Fibonacci<1>::value == 1);
static_assert(Fibonacci<2>::value == 1);
static_assert(Fibonacci<3>::value == 2);
static_assert(Fibonacci<4>::value == 3);
static_assert(Fibonacci<5>::value == 5);
static_assert(Fibonacci<6>::value == 8);
static_assert(Fibonacci<7>::value == 13);
static_assert(
  Fibonacci<41>::value % 2 == 1
); // Useful for benchmarking, make sure your compiler calculates LHS.
