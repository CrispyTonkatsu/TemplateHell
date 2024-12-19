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

// TODO: Left off here
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

template<int P, int... I>
using PrependT = Prepend<>;

  static_assert(std::is_same_v<PrependT<1, Vector<2, 3>>, Vector<1, 2, 3>>);

/**
 * 5. Define Append.
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(std::is_same_v< Append<4, Vector<1,2,3>>::type ,
// Vector<1,2,3,4> >);

/**
 * 6. Define PopBack.
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(std::is_same_v< PopBack<Vector<1,2,3,4>>::type , Vector<1,2,3>
// >);

/**
 * 7. Define RemoveFirst, that removes the first occurence of element R from
 * vector V.
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(std::is_same_v<RemoveFirst<1, Vector<1,1,2>>::type,
// Vector<1,2>>);

/**
 * 8. Define RemoveAll, that removes all occurences of element R from vector V.
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(std::is_same_v<RemoveAll<9, Vector<1,9,2,9,3,9>>::type,
// Vector<1,2,3>>);

/**
 * 9. Define Length.
 * Hint: Use `static constexpr int value = ...` inside the struct.
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(Length<Vector<1,2,3>>::value == 3);

/**
 * 10. Define length, which works like Length<V>::value.
 * Hint: See how is_same_v is defined in terms of is_same.
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(length<Vector<>> == 0);
// static_assert(length<Vector<1,2,3>> == 3);

/**
 * 11. Define Min, that stores the minimum of a vector in its property `value`.
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(Min<Vector<3,1,2>>::value == 1);
// static_assert(Min<Vector<1,2,3>>::value == 1);
// static_assert(Min<Vector<3,2,1>>::value == 1);

/**
 * 12. Define Sort.
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(std::is_same_v<Sort<Vector<4,1,2,5,6,3>>::type,
// Vector<1,2,3,4,5,6>>);
// static_assert(std::is_same_v<Sort<Vector<3,3,1,1,2,2>>::type,
// Vector<1,1,2,2,3,3>>);
// static_assert(std::is_same_v<Sort<Vector<2,2,1,1,3,3>>::type,
// Vector<1,1,2,2,3,3>>);

/**
 * 13. Define Uniq.
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(std::is_same_v<Uniq<Vector<1,1,2,2,1,1>>::type,
// Vector<1,2,1>>);

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
