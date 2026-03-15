#include <type_traits>
#include "vector.hpp"

/**
 * 14. Define type Set.
 */

template<int... I>
struct Set
{
  using type = Uniq<typename Sort<Vector<I...>>::type>::type;
};

static_assert(std::is_same_v<Set<2, 1, 3, 1, 2, 3>::type, Set<1, 2, 3>::type>);

/**
 * 15. Define SetFrom.
 */

template<typename V>
struct SetFrom
{
};

template<int... I>
struct SetFrom<Vector<I...>>
{
  using type = Set<I...>::type;
};

static_assert(
  std::is_same_v<SetFrom<Vector<2, 1, 3, 1, 2, 3>>::type, Set<1, 2, 3>::type>
);
