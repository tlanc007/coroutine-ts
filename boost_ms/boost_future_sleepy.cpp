/**
 * sleepy examaple using boost:asio and std::chrono
 *     output: tick1, tick2, tick3 100ms apart.
 *
 *  From Microsoft Blog:
 *  https://blogs.msdn.microsoft.com/vcblog/2017/05/19/using-c-coroutines-with-boost-c-libraries/
 *
 *  -- Tal 2017-07-11.
 */

#include "future_coro.hpp"
#include "boost_asio_awaitTimer.hpp"

using namespace boost::asio;
using namespace std::chrono;

boost::future<void> sleepy(io_service &io) {
    system_timer timer(io);
    co_await async_await(timer, 100ms);
    puts("tick1");
    co_await async_await(timer, 100ms);
    puts("tick2");
    co_await async_await(timer, 100ms);
    puts("tick3");
}

int main() {
    io_service io;
    sleepy(io);
    io.run();
}


