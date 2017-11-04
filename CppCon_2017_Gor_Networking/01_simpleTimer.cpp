/*
 01_simpleTimer.cpp
    Two timers one for 15 hours and the other for 1 seconds
    Program will run for 1 second as the io.stop ends the io_context
    killing the 15 hour timer.
 
 From Gor Nishanov Cpp2017 Coroutines live networking talk
 
 Copied from slides with some tweaks to so it would compile. -- Tal Lancaster 2017 11 04
 */

#include <experimental/net>

namespace  net = std::experimental::net;

int main ()
{
    net::io_context io;

    net::system_timer slow_timer (io, net::chrono::hours (15) );
    slow_timer.async_wait ([] (auto) {
        puts ("Timer fired");
    } );

    net::system_timer fast_timer (io, net::chrono::seconds (1) );
    fast_timer.async_wait ([&io] (auto) {
        io.stop ();
    } );

    io.run ();
}

