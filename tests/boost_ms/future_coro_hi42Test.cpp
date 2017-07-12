#include <sstream>

#include "future_coro.hpp"

#include "RedirectStdOut.h"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

boost::future<void> f()
{
    std::cout << "Hi!\n"; // can't capture puts, so switch to cout
    co_return;
}

boost::future<int> g()
{
    co_return 42;
}

TEST_CASE ("future_coro_hi42Test", "[future_coro_hi42]")
{
    const std::string fCapture {"Hi!\n"};
    constexpr auto gCapture {42};
    std::stringstream os {};
    {
        RedirectStdOut rdOut {os};
        f().get();

        CHECK (gCapture == g().get() );
    }

    CHECK (fCapture == os.str () );
}

