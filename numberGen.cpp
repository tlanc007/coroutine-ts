/*
 * coroutines simple number generator example
 *
 * % clang++ -std=c++14 -fcoroutines-ts -stdlib=libc++ numberGen.cpp
 *
 * Tal 2017-06-27
 */

#include <iostream>
#include <experimental/coroutine>

#include "generator.hpp"

generator <unsigned long> numGen (unsigned long n)
{
    for (auto i {0ul}; i < n; ++i) {
        co_yield i;
    }
}

int main ()
{
    for (auto e: numGen (5) ) {
        std::cout << e << "\n";
    }
}
