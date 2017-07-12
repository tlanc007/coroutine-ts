/**
 *  boost::asio::system_timer async_await
 *
 *  From Microsoft Blog:
 *  https://blogs.msdn.microsoft.com/vcblog/2017/05/19/using-c-coroutines-with-boost-c-libraries/
 *
 *  -- Tal 2017-07-11.
 */

#include <experimental/coroutine>
#include <boost/asio/system_timer.hpp>

template <typename R, typename P>
auto async_await(boost::asio::system_timer &t, std::chrono::duration<R, P> d) {
    struct Awaiter {
        boost::asio::system_timer &t;
        std::chrono::duration<R, P> d;
        boost::system::error_code ec;

        bool await_ready() { return d.count() == 0; }
        void await_resume() {
            if (ec)
                throw boost::system::system_error(ec);
        }
        void await_suspend(std::experimental::coroutine_handle<> coro) {
            t.expires_from_now(d);
            t.async_wait([this, coro](auto ec) {
                this->ec = ec;
                coro.resume();
            }); 
        } 
    }; 
    return Awaiter{ t, d }; 
}

