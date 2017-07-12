/**
 * Testing use of boost::future
 *      Output: 42
 *
 *  From Microsoft Blog:
 *  https://blogs.msdn.microsoft.com/vcblog/2017/05/19/using-c-coroutines-with-boost-c-libraries/
 *
 *  compile: clang++ -std=c++14 -I/usr/local/include -lboost_thread -lboost_system -lboost_exception future_42.cpp
 *
 *  -- Tal 2017-07-11.
 */

#define BOOST_THREAD_PROVIDES_FUTURE
#define BOOST_THREAD_PROVIDES_FUTURE_CONTINUATION // Enables future::then
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <cstdio>

using namespace boost;
using namespace boost::asio;

int main() {
    io_service io;
    promise<int> p;
    auto f {p.get_future() };

    io.post([&] { p.set_value(42); });
    io.run();

    printf("%d\n", f.get());
}


