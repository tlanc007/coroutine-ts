/*
 * coroutines simple number generator example
 *
 * % clang++ -std=c++14 -fcoroutines-ts -stdlib=libc++ fibonacciGen.cpp
 *
 * Tal 2017-06-27
 */

#include <iostream>
#include <experimental/coroutine>

#include "generator.hpp"

/*
 Iterative infinite fibonacci sequence generator
 it reuses the previous call as the starting base for the next number
 */
generator <unsigned long> fibGen ()
{
    constexpr auto Fib0 {0};
    constexpr auto Fib1 {1};

    auto a {Fib0};
    auto b {Fib1};
    while (true) {
        co_yield b;
        auto tmp {a + b};
        a = b;
        b = tmp;
    }
}

// also using a sentinel to stop the generator at specified point
generator <unsigned long> take_until (generator <unsigned long>& g, size_t sentinel)
{
    auto i {0ul};
    for (auto e: g) {
        if (i == sentinel)  {
            break;
        }
        co_yield e;
        ++i;
    }
}

int main ()
{
    constexpr auto Sentinel {10ul};
    auto g {fibGen () };
    auto t {take_until (g, Sentinel) };

    for (auto e: t) {
        std::cout << e << "\n";
    }
}
