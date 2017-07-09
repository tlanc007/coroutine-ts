#include <iostream>

#include "../generator.hpp"

#pragma once

template <typename RangeOfRanges>
auto buildIteratorContainer (RangeOfRanges& rg)
{
    using T = decltype (std::begin (rg[0]) );
    using T = std::remove_reference_t<decltype (std::begin(rg[0]) ) >;
    std::vector <T> v {};
    std::for_each (std::begin (rg), std::end (rg), [&v](auto&& r) {
        v.emplace_back (std::begin (r) );
    } );

    return v;
}

template <typename RangeOfRanges>
auto interleaveNonCoroutine (RangeOfRanges& rg) -> void {
    auto rng {buildIteratorContainer (rg) };

    while (1) {
        auto values_yielded_this_iteration {0u};
        auto i {0u};
        for (auto&& e: rng) {
            if (e != std::end (rg[i] ) ) {
                std::cout << *e << ' ';
                ++values_yielded_this_iteration;
                ++e;
            }
            ++i;
        }
        if (values_yielded_this_iteration == 0) {
            std::cout << '\n';
            return;
        }
    }
}

template <typename RangeOfRanges>
auto interleaveCoroutine (RangeOfRanges& rg) -> generator <int>
{
    auto rng {buildIteratorContainer (rg) };

    while (1) {
        auto values_yielded_this_iteration {0u};
        auto i {0u};
        for (auto&& e: rng) {
            if (e != std::end (rg[i] ) ) {
                co_yield *e;
                ++values_yielded_this_iteration;
                ++e;
            }
            ++i;
        }
        if (values_yielded_this_iteration == 0) {
            co_return;
        }
    }
}


