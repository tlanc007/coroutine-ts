/**
 * resumable_thing example: counter
 * From James McNellis: Introduction to C++ Coroutines CppCon 2016.
 *
 * compile: clang++ -std=c++14 -fcoroutines-ts resumable_thing1.cpp
 * Tal Lancaster 2017-06-30
 **/

#include <iostream>

#include "resumable_thing1.hpp"

resumable_thing counter ()
{
    std::cout << "counter: called\n";
    for (auto i {1u}; ; ++i) {
        co_await std::experimental::suspend_always ();
        std::cout << "counter: resumed (#" << i << ")\n";
    }
}

#ifndef AS_TEST
int main ()
{
    std::cout << "main: calling counter\n";
    resumable_thing the_counter {counter () };
    std::cout << "main: resuming counter\n";

    the_counter.resume ();
    the_counter.resume ();

    std::cout << "main: done\n";
}
#endif // AS_TEST
