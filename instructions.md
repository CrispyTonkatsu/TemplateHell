[Source](https://www.slamecka.cz/posts/2021-03-17-cpp-metaprogramming-exercises-1/)

This is a set of exercises for type level programming in C++, suitable for
beginners or as a refresher for intermediate programmers.

Scope:
- Most exercises in this set are confined to vectors of integers for simplicity.
- Exercises are centered around basic functional techniques since they are easy to express with template metaprogramming.

How to solve it:
- You should be able to compile with gcc version 10.2, g++ --std=c++20 typelevel_set1.cpp
- You should understand the requested behaviours from static_assert-s,
except for print, which comes with a test in main().
- Tests are commented-out and you should uncomment them as you go.
- You might want to read some introductory material before attempting these:

[Templates](https://en.cppreference.com/w/cpp/language/templates)

[Parameter Packs](https://en.cppreference.com/w/cpp/language/parameter_pack)

[Template Parameters](https://en.cppreference.com/w/cpp/language/template_parameters)
in this set we'll only see non-type template parameters and type template parameters

[Traits](https://en.cppreference.com/w/cpp/header/type_traits)

[Partial Specialization](https://en.cppreference.com/w/cpp/language/partial_specialization)
[More on Partial Specialization](https://stackoverflow.com/questions/17005985/what-is-the-partial-ordering-procedure-in-template-deduction)
