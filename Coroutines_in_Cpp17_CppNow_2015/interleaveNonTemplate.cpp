/*
 * Interleave Example from CppNow_2015 Coroutines in C++17 -- Gor Nishanov
 *
 * Reimplemented using gsl::span; non-template version make example a little less complicated.
 *   instead of the Range_t struct in the example -- Tal 2017.07.06
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <gsl/gsl>

#include "../generator.hpp"

using VecSpan = std::vector <gsl::span <int> >;

auto dropFirst (gsl::span <int>& rng) -> gsl::span <int>
{
    return rng.subspan (1);
}

auto interleaveNonCoroutine (VecSpan rg) -> void
{
    while (1) {
        auto values_yielded_this_iteration {0u};
        auto i {0u};
        for (auto&& e: rg) {
            auto front {std::begin (e) };
            if (front != std::end (e) ) {
                std::cout << *front << ' ';
                e = dropFirst (e);
                ++values_yielded_this_iteration;
            }
            ++i;
        }
        if (values_yielded_this_iteration == 0) {
            std::cout << '\n';
            return;
        }
    }
}

auto interleaveCoroutine (VecSpan rg) -> generator <int>
{
    while (1) {
        auto values_yielded_this_iteration {0u};
        auto i {0u};
        for (auto&& e: rg) {
            auto front {std::begin (e) };
            if (front != std::end (e) ) {
                co_yield *front;
                e = dropFirst (e);
                ++values_yielded_this_iteration;
            }
            ++i;
        }
        if (values_yielded_this_iteration == 0) {
            co_return;
        }
    }
}

int main () {
    std::vector <int> a {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector <int> b {10, 20, 30, 40, 50};
    std::vector <int> c {100, 200, 300, 400};

    VecSpan rng {gsl::make_span (a), gsl::make_span (b), gsl::make_span (c) };
    interleaveNonCoroutine (rng);

    for (const auto& e: interleaveCoroutine (rng) ) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}

