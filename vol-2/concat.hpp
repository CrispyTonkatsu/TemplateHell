#include <type_traits>

/**
 * 2. Define Concat that takes two vectors and concatenates them into one.
 *
 * This is a warmup before the next exercise.
 */

template<int...>
struct Vector
{
};

template<typename V0, typename V1>
struct Concat;

template<int... I0, int... I1>
struct Concat<Vector<I0...>, Vector<I1...>>
{
  using type = Vector<I0..., I1...>;
};

static_assert(
  std::is_same_v<Concat<Vector<1, 2>, Vector<3, 4>>::type, Vector<1, 2, 3, 4>>
);
