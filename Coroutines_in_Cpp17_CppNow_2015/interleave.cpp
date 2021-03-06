/*
 * Interleave Example from CppNow_2015 Coroutines in C++17 -- Gor Nishanov
 *
 * Reimplemented using gsl::span and templates
 *   instead of the Range_t struct in the example -- Tal 2017.07.05
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <gsl/gsl>

#include "RangeOfRanges.hpp"

#ifndef AS_TEST
int main () {
    std::vector <int> a {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector <int> b {10, 20, 30, 40, 50};
    std::vector <int> c {100, 200, 300, 400};

    using T = std::remove_reference_t<decltype (*(std::begin(c) ) )>;
    std::vector <gsl::span<T> > rng {gsl::make_span (a), gsl::make_span (b), gsl::make_span (c) };
    interleaveNonCoroutine (rng);

    for (const auto& e: interleaveCoroutine (rng) ) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}
#endif // AS_TEST
