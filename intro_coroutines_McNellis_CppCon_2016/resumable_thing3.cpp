
/**
 * resumable_thing_3 example: get_value ()
 * From James McNellis: Introduction to C++ Coroutines CppCon 2016.
 * 
 * compile: clang++ -std=c++14 -fcoroutines-ts resumable_thing3.cpp
 * Tal Lancaster 2017-07-01
 *   split out class into resumable_thing3.hpp
 **/

#include <iostream>

#include "resumable_thing3.hpp"

resumable_thing get_value ()
{
    std::cout << "get_value: called\n";
    co_await std::experimental::suspend_always ();
    std::cout << "get_value: resumed\n";
    co_return 30;
}

#ifndef AS_TEST
int main ()
{
    std::cout << "main:     calling get_value\n";
    resumable_thing value {get_value () };
    std::cout << "main:     resuming get_value\n";
    value.resume ();
    std::cout << "main:     value was: " << value.get () << "\n";
}
#endif // AS_TEST
