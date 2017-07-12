# boost Microsoft blog
The examples here are from the Microsoft blog [Using C++ Coroutines with Boost](https://blogs.msdn.microsoft.com/vcblog/2017/05/19/using-c-coroutines-with-boost-c-libraries).

# Background
These have been tweaked to work with clang/llvm 5.0.  The examples make use of boost (1.60.0 min).  You will need to have this installed before they can be built.

All of the examples have corrisponding Test versions.

# Examples
## future_42
This example isn't using coroutines.  It is just making sure that you have boost installed and working properly.

## future coro hi 42
This is a coroutine version of the future_42 example.  This version goes a little further by having another coroutine that display's "Hi!".

This example also introduces **future_coro.hpp** which contains the specializaitons to extend boost::future.

## future_coawait
This example extends **future_coro.hpp** by adding co_await to boost::future.  This is making use of the Awaiter pattern.

**NOTE**: The blog gives some interesting background on the implementation of **await_suspend**().  I opted for the application side efficiency.  But if this was for a server, then the other implementation would be the way to go.

## boost_asio
This is a non-coroutine example using asio::async_wait to wait and receive value.

## boost future sleepy
A coroutine version using asio::async to wait on a number of values.

This version introduces boost_asio_awaitTimer.hpp, which implements an async_await based on the Awaiter pattern.

