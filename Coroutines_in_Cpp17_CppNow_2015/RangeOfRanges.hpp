#include <iostream>

#include "generator.hpp"

#pragma once

template <typename SpanT>
auto dropFirst (SpanT& rng) -> SpanT
{
    return rng.subspan (1);
}

template <typename RangeOfRanges>
auto interleaveNonCoroutine (RangeOfRanges rg) -> void {
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

template <typename RangeOfRanges>
auto interleaveCoroutine (RangeOfRanges rg) -> generator <int>
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


