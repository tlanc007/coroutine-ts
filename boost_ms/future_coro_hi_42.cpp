/**
 * future with coroutine support.
 *
 *  From Microsoft Blog:
 *  https://blogs.msdn.microsoft.com/vcblog/2017/05/19/using-c-coroutines-with-boost-c-libraries/
 *
 *  test future specialization - output: Hi! 42.
 *
 *  -- Tal 2017-07-11.
 */

#include "future_coro.hpp"

boost::future<void> f()
{
    puts("Hi!");
    co_return;
}

boost::future<int> g()
{
    co_return 42;
}

int main()
{
    f().get();
    printf("%d\n", g().get());
}
