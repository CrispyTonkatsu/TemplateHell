#include <cstddef>
#include <iostream>
#include <ostream>
#include <type_traits>

/**
 * 1. Define Vector, a template level list of integers.
 * Hint: Use non-type template parameter pack.
 */

template<int...>
class Vector
{
};

static_assert(std::is_same_v<Vector<1, 2>, Vector<1, 2>>);
static_assert(!std::is_same_v<Vector<>, Vector<1, 2>>);
static_assert(!std::is_same_v<Vector<1, 3>, Vector<1, 2>>);

/**
 * 2. Define function print() that prints Vector-s.
 * Example: print(Vector<1,2,3>{}); // prints "1 2 3" (newline)
 * See main() below.
 */

template<typename T>
auto print_item(T to_print) -> void
{
  std::cout << to_print << std::endl;
}

template<typename T, typename... R>
auto print_item(T to_print, R... remaining) -> void
{
  std::cout << to_print << ", ";
  print_item(remaining...);
}

template<int I, int... R>
auto print(Vector<I, R...>) -> void
{
  print_item(I, R...);
}

template<int... R>
auto print(Vector<>) -> void
{
  std::cout << std::endl;
}

/**
 * 3. Define Prepend.
 * Hint: Use `using type = ...` inside a struct that has both non-type and type
 * template parameters.
 */

template<int P, typename V>
struct Prepend
{
};

template<int P, int... I>
struct Prepend<P, Vector<I...>>
{
  using type = Vector<P, I...>;
};

static_assert(std::is_same_v<Prepend<1, Vector<2, 3>>::type, Vector<1, 2, 3>>);

/**
 * 4. Define PrependT that can be used without ::type.
 * Hint: See how enable_if_t is defined in terms of enable_if.
 *
 * This technique is not used further to reduce boilerplate.
 */

template<int P, typename V>
using PrependT = Prepend<P, V>::type;

static_assert(std::is_same_v<PrependT<1, Vector<2, 3>>, Vector<1, 2, 3>>);

/**
 * 5. Define Append.
 */

template<int P, typename V>
struct Append
{
  using type = void;
};

template<int P, int... I>
struct Append<P, Vector<I...>>
{
  using type = Vector<I..., P>;
};

static_assert(std::is_same_v<Prepend<1, Vector<2, 3>>::type, Vector<1, 2, 3>>);

static_assert(
  std::is_same_v<Append<4, Vector<1, 2, 3>>::type, Vector<1, 2, 3, 4>>
);

/**
 * 6. Define PopBack.
 */

template<typename V>
struct PopBack
{
};

template<int First, int Second, int... Rest>
struct PopBack<Vector<First, Second, Rest...>>
{
  using type =
    Prepend<First, typename PopBack<Vector<Second, Rest...>>::type>::type;
};

template<int Last, int... Rest>
struct PopBack<Vector<Last, Rest...>>
{
  using type = Vector<Rest...>;
};

static_assert(
  std::is_same_v<PopBack<Vector<1, 2, 3, 4>>::type, Vector<1, 2, 3>>
);

/**
 * 7. Define RemoveFirst, that removes the first occurence of element R from
 * vector V.
 */

template<int I, typename V>
struct RemoveFirst
{
};

template<int ToRemove, int... Rest>
struct RemoveFirst<ToRemove, Vector<ToRemove, Rest...>>
{
  using type = Vector<Rest...>;
};

template<int ToRemove, int First, int... Rest>
struct RemoveFirst<ToRemove, Vector<First, Rest...>>
{
  using type =
    Prepend<First, typename RemoveFirst<ToRemove, Vector<Rest...>>::type>::type;
};

template<int ToRemove, int... Rest>
struct RemoveFirst<ToRemove, Vector<Rest...>>
{
  using type = Vector<Rest...>;
};

static_assert(
  std::is_same_v<RemoveFirst<1, Vector<1, 1, 2>>::type, Vector<1, 2>>
);
static_assert(
  std::is_same_v<RemoveFirst<3, Vector<1, 3, 2>>::type, Vector<1, 2>>
);
static_assert(
  std::is_same_v<RemoveFirst<2, Vector<1, 3, 2>>::type, Vector<1, 3>>
);
static_assert(std::is_same_v<RemoveFirst<2, Vector<>>::type, Vector<>>);

/**
 * 8. Define RemoveAll, that removes all occurences of element R from vector V.
 */

template<int I, typename V>
struct RemoveAll
{
};

template<int ToRemove, int... Rest>
struct RemoveAll<ToRemove, Vector<ToRemove, Rest...>>
{
  using type = RemoveAll<ToRemove, Vector<Rest...>>::type;
};

template<int ToRemove, int First, int... Rest>
struct RemoveAll<ToRemove, Vector<First, Rest...>>
{
  using type =
    Prepend<First, typename RemoveAll<ToRemove, Vector<Rest...>>::type>::type;
};

template<int ToRemove, int... Rest>
struct RemoveAll<ToRemove, Vector<Rest...>>
{
  using type = Vector<Rest...>;
};

static_assert(
  std::is_same_v<RemoveAll<9, Vector<1, 9, 2, 9, 3, 9>>::type, Vector<1, 2, 3>>
);

/**
 * 9. Define Length.
 * Hint: Use `static constexpr int value = ...` inside the struct.
 */

template<typename V>
struct Length
{
  static constexpr int value = 0;
};

template<int I, int... R>
struct Length<Vector<I, R...>>
{
  static constexpr int value =
    Length<Vector<I>>::value + Length<Vector<R...>>::value;
};

template<int I>
struct Length<Vector<I>>
{
  static constexpr int value = 1;
};

static_assert(Length<Vector<1, 2, 3>>::value == 3);
static_assert(Length<Vector<2, 3>>::value == 2);

/**
 * 10. Define length, which works like Length<V>::value.
 * Hint: See how is_same_v is defined in terms of is_same.
 */

template<typename V>
static constexpr size_t length = Length<V>::value;

static_assert(length<Vector<>> == 0);
static_assert(length<Vector<1, 2, 3>> == 3);

/**
 * 11. Define Min, that stores the minimum of a vector in its property `value`.
 */

template<typename V>
struct Min
{
};

template<int I>
struct Min<Vector<I>>
{
  static constexpr int value = I;
};

template<int A, int B>
struct Min<Vector<A, B>>
{
  static constexpr int value = A < B ? A : B;
};

template<int A, int B, int... R>
struct Min<Vector<A, B, R...>>
{
  static constexpr int a = Min<Vector<A, B>>::value;
  static constexpr int b = Min<Vector<R...>>::value;

  static constexpr int value = a < b ? a : b;
};

static_assert(Min<Vector<3, 1, 2>>::value == 1);
static_assert(Min<Vector<1, 2, 3>>::value == 1);
static_assert(Min<Vector<3, 2, 1>>::value == 1);

/**
 * 12. Define Sort.
 */

template<typename A, typename B>
struct SortImpl;

template<int... P, int H, int... R>
struct SortImpl<Vector<P...>, Vector<H, R...>>
{
  // Performing selection sort
  static constexpr int min = Min<Vector<H, R...>>::value;
  using rest = RemoveFirst<min, Vector<H, R...>>::type;

  using type = SortImpl<typename Append<min, Vector<P...>>::type, rest>::type;
};

template<int... P, int... R>
struct SortImpl<Vector<P...>, Vector<R...>>
{
  using type = Vector<P...>;
};

template<typename V>
struct Sort;

template<int... I>
struct Sort<Vector<I...>>
{
  using type = SortImpl<Vector<>, Vector<I...>>::type;
};

static_assert(
  std::is_same_v<Sort<Vector<4, 1, 2, 5, 6, 3>>::type, Vector<1, 2, 3, 4, 5, 6>>
);
static_assert(
  std::is_same_v<Sort<Vector<3, 3, 1, 1, 2, 2>>::type, Vector<1, 1, 2, 2, 3, 3>>
);
static_assert(
  std::is_same_v<Sort<Vector<2, 2, 1, 1, 3, 3>>::type, Vector<1, 1, 2, 2, 3, 3>>
);

/**
 * 13. Define Uniq.
 */

template<typename T, typename V>
struct UniqImpl;

template<int... P>
struct UniqImpl<Vector<P...>, Vector<>>
{
  using type = Vector<P...>;
};

template<int... P, int A, int B, int... R>
struct UniqImpl<Vector<P...>, Vector<A, B, R...>>
{
  using type = std::conditional_t<
    A == B,
    typename UniqImpl<Vector<P..., A>, Vector<R...>>::type,
    typename UniqImpl<Vector<P..., A>, Vector<B, R...>>::type>;
};

template<int... P, int A>
struct UniqImpl<Vector<P...>, Vector<A>>
{
  using type = Vector<P..., A>;
};

template<typename T>
struct Uniq;

template<int... I>
struct Uniq<Vector<I...>>
{
  using type = UniqImpl<Vector<>, Vector<I...>>::type;
};

static_assert(
  std::is_same_v<Uniq<Vector<1, 1, 2, 2, 1, 1>>::type, Vector<1, 2, 1>>
);

/**
 * 16. Define Get for Vector.
 * Provide an improved error message when accessing outside of Vector bounds.
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(Get<0, Vector<0,1,2>>::value == 0);
// static_assert(Get<1, Vector<0,1,2>>::value == 1);
// static_assert(Get<2, Vector<0,1,2>>::value == 2);
// static_assert(Get<9, Vector<0,1,2>>::value == 2); // How good is your error
// message?

/**
 * 17. Define BisectLeft for Vector.
 * Given n and arr, return the first index i such that arr[i] >= n.
 * If it doesn't exist, return the length of the array.
 *
 * Don't worry about complexity but aim for the binary search pattern.
 *
 * Hint: You might find it convenient to define a constexpr helper function.
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(BisectLeft<  3, Vector<0,1,2,3,4>>::value == 3);
// static_assert(BisectLeft<  3, Vector<0,1,2,4,5>>::value == 3);
// static_assert(BisectLeft<  9, Vector<0,1,2,4,5>>::value == 5);
// static_assert(BisectLeft< -1, Vector<0,1,2,4,5>>::value == 0);
// static_assert(BisectLeft<  2, Vector<0,2,2,2,2,2>>::value == 1);

/**
 * 18. Define Insert for Vector, it should take position, value and vector.
 * Don't worry about bounds.
 * Hint: use the enable_if trick, e.g.
 *   template<typename X, typename Enable = void> struct Foo;
 *   template<typename X> struct<std::enable_if_t<..something      about X..>>
 * Foo {...}; template<typename X> struct<std::enable_if_t<..something else
 * about X..>> Foo {...};
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(std::is_same_v<Insert<0, 3, Vector<4,5,6>>::type,
// Vector<3,4,5,6>>); static_assert(std::is_same_v<Insert<1, 3,
// Vector<4,5,6>>::type, Vector<4,3,5,6>>);
// static_assert(std::is_same_v<Insert<2, 3, Vector<4,5,6>>::type,
// Vector<4,5,3,6>>); static_assert(std::is_same_v<Insert<3, 3,
// Vector<4,5,6>>::type, Vector<4,5,6,3>>);
