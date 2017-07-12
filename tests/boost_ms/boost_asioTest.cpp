/*
 * boost_asioTest.cpp based off of boost_asio.cpp
 *   Changed output to cout so can capture.
 */

#include <sstream>

#include <boost/asio/system_timer.hpp>
#include <boost/thread.hpp>

#include "RedirectStdOut.h"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

using namespace boost::asio;
using namespace std::chrono;

TEST_CASE ("boost_asioTest", "[boost_asio]")
{
    const std::string CapturedOutput {
R"(waiting for a tick
tick
)"
    };

    std::stringstream os {};
    io_service io;
    system_timer timer(io);

    {
        RedirectStdOut rdOut {os};
        timer.expires_from_now(100ms);
        timer.async_wait([](boost::system::error_code ec) {
            if (ec) std::cout << "timer failed: " << ec.value() << '\n';
            else std::cout << "tick\n";
        } );

        std::cout << "waiting for a tick\n";
        io.run();
    }

    CHECK (CapturedOutput == os.str () );
}


