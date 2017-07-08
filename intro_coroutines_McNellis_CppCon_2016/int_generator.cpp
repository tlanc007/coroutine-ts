
/**
 * generator example: int_generator
 * From James McNellis: Introduction to C++ Coroutines CppCon 2016.
 *
 * compile: clang++ -std=c++14 -fcoroutines-ts int_generator.cpp
 * Tal Lancaster 2017-07-01
 **/

#include <iostream>

#include "int_generator.hpp"

int_generator integers (int first, int last)
{
    for (auto i {first}; i <= last; ++i) {
        co_yield i;
    }
}

#ifndef AS_TEST
int main ()
{
    for (int x: integers (1, 5) ) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}
#endif // AS_TEST
