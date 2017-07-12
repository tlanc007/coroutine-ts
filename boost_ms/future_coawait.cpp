/**
 * Specializing boost::future for coroutine support
 *
 *  From Microsoft Blog:
 *  https://blogs.msdn.microsoft.com/vcblog/2017/05/19/using-c-coroutines-with-boost-c-libraries/
 *
 *  test future specialization - output: Hi! 42.
 *
 *  -- Tal 2017-07-11.
 */

#include "future_coro.hpp"

boost::future<int> g()
{
    co_return 42;
}

boost::future<void> f ()
{
    printf ("%d\n", co_await (g () ) );
}

int main()
{
    f().get();
}


