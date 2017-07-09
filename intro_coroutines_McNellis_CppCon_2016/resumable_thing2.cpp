
/**
 * resumable_thing_2 example: named_counter
 * From James McNellis: Introduction to C++ Coroutines CppCon 2016.
 *
 * compile: clang++ -std=c++14 -fcoroutines-ts resumable_thing2.cpp
 * Tal Lancaster 2017-06-30
 *  split out class into how header file. -- tal 2017-07-08
 **/

#include <iostream>

#include "resumable_thing2.hpp"

resumable_thing named_counter (std::string name)
{
    std::cout << "counter(" << name << ") was called\n";
    for (auto i {1u}; ; ++i) {
        co_await std::experimental::suspend_always ();
        std::cout << "counter(" << name << ") resumed # " << i << "\n";
    }
}

#ifndef AS_TEST
int main ()
{
    resumable_thing counter_a {named_counter ("a") };
    resumable_thing counter_b {named_counter ("b") };
    counter_a.resume ();
    counter_b.resume ();
    counter_b.resume ();
    counter_a.resume ();
}
#endif // AS_TEST
