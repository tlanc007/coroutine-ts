#include <sstream>

#include "future_coro.hpp"

#include "RedirectStdOut.h"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

boost::future<int> g()
{
    co_return 42;
}

boost::future<void> f ()
{
    std::cout << co_await (g () ) << '\n';
}

TEST_CASE ("future_coawitTest", "[future_coawait]")
{
    const std::string Expected {"42\n"};
    std::stringstream os {};
    {
        RedirectStdOut rdOut {os};
        f().get();
    }

    CHECK (Expected == os.str () );
}
