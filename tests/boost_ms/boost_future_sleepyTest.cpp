/*
 * boost_asioSleepyTest.cpp based off of boost_future_sleepy.cpp
 *   Changed output to cout so can capture.
 */


#include <sstream>

#include "future_coro.hpp"
#include "boost_asio_awaitTimer.hpp"

#include "RedirectStdOut.h"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

using namespace boost::asio;
using namespace std::chrono;

boost::future<void> sleepy(io_service &io) {
    system_timer timer(io);
    co_await async_await(timer, 100ms);
    std::cout << "tick1\n";
    co_await async_await(timer, 100ms);
    std::cout << "tick2\n";
    co_await async_await(timer, 100ms);
    std::cout << "tick3\n";
}

TEST_CASE ("boost_future_sleepyTest", "[boost_future_sleepy]")
{
    const std::string CaptureOutput {
R"(tick1
tick2
tick3
)"
    };

    std::stringstream os {};
    io_service io;
    sleepy(io);
    {
        RedirectStdOut rdOut {os};
        io.run();
    }

    CHECK (CaptureOutput == os.str () );
}



