
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#define BOOST_THREAD_PROVIDES_FUTURE
#define BOOST_THREAD_PROVIDES_FUTURE_CONTINUATION // Enables future::then
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <cstdio>

using namespace boost;
using namespace boost::asio;

TEST_CASE ("future_42Test", "[future_42]")
{
    constexpr auto expected {42};
    io_service io {};
    promise<int> p {};
    auto f {p.get_future() };

    io.post([&] { p.set_value(42); });
    io.run();

    CHECK (expected == f.get() );
}

