/*
 * Interleave Example from CppNow_2015 Coroutines in C++17
 *
 *  Note: This version example is included for historical reference.
 *     For the most part this code is as Gor shared with me.  
 *
 *     At the time C++ didn't have a "standard" way of dealing with the
 *     collection of ranges.  Which is the reason for the Range_t.
 *     Today it is preferable to instead to use span.  The example: interleave.cpp
 *     is one example of how to use gsl::span instead of the Range_t below.
 *
 * My only tweak was to change the generator to point to the version
 * in my repo. (Unlike MSVC++ clang/llvm doesn't include a generator). -- Tal 2017.07.05.
 *
 */

//#include <experimental/generator>
#include <vector>
#include <iostream>

#include "../generator.hpp"

using namespace std::experimental;
using namespace std;

template <typename T>
struct Range_t {
    T const* beg;
    T const* end;

    Range_t(T const* beg, size_t size) : beg(beg), end(beg + size) {}

    Range_t operator++(int) {
        auto result = *this;
        ++beg;
        return result;
    }
};
template <typename T>
T const* begin(Range_t<T> const& r) {
    return r.beg;
}
template <typename T>
T const* end(Range_t<T> const& r) {
    return r.end;
}
template <typename T>
Range_t<T> Range(vector<T>const& v) {
    return { v.data(), v.size() };
}

template <typename RangeOfRanges>
auto interleave_without_coroutines(RangeOfRanges rg)
{
    using T = remove_reference_t<decltype(*begin(rg))>;
    vector<T> ranges(begin(rg), end(rg));

    for (;;) {
        int values_yielded_this_iteration = 0;
        for (auto && v : ranges)
            if (begin(v) != end(v)) {
                cout << ' ' << *begin(v++) ;
                ++values_yielded_this_iteration;
            }
        if (values_yielded_this_iteration == 0) {
            putchar('\n'); return;
        }
    }
}

template <typename RangeOfRanges>
generator<int> interleave(RangeOfRanges rg)
{
    using T = remove_reference_t<decltype(*begin(rg))>;
    vector<T> ranges(begin(rg), end(rg));

    for (;;) {
        int values_yielded_this_iteration = 0;
        for (auto && v : ranges)
            if (begin(v) != end(v)) {
                co_yield *begin(v++);
                ++values_yielded_this_iteration;
            }
        if (values_yielded_this_iteration == 0)
            co_return;
    }
}

int main() {
    vector<int> a{ 1,2,3,4,5,6,7,8,9 };
    vector<int> b{ 10,20,30,40,50 };
    vector<int> c{ 100,200,300,400 };

    vector<Range_t<int>> rg{ Range(a), Range(b), Range(c) };
    
    interleave_without_coroutines(rg);
    
    for (auto v : interleave(rg)) {
        cout << v << ' ';
    }
    cout << '\n';
}

