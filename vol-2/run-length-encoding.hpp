#include <type_traits>

template<int...>
struct Vector
{
};

// TODO: Left off here

/**
 * 3. Run Length Encoding
 */

template<int... I>
struct RLE
{
  using type = int;
};

static_assert(
  std::is_same_v<
    RLE<0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1>::type,
    Vector<5, 0, 2, 1, 12, 0, 1, 1>>
);
static_assert(
  std::is_same_v<RLE<1, 1, 1, 1, 9, 9, 9, 2>::type, Vector<4, 1, 3, 9, 1, 2>>
);
