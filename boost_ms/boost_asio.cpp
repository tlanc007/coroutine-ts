/**
 * boost::asio (not coroutine)
 *
 *  From Microsoft Blog:
 *  https://blogs.msdn.microsoft.com/vcblog/2017/05/19/using-c-coroutines-with-boost-c-libraries/
 *
 *  -- Tal 2017-07-11.
 */

#include <boost/asio/system_timer.hpp>
#include <boost/thread.hpp>

using namespace boost::asio;
using namespace std::chrono;

int main() {
    io_service io;
    system_timer timer(io);

    timer.expires_from_now(100ms);
    timer.async_wait([](boost::system::error_code ec) {
        if (ec) printf("timer failed: %d\n", ec.value());
        else puts("tick");
    });

    puts("waiting for a tick");
    io.run(); 
}

