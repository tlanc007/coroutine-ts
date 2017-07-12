/**
 * Specializing boost::future for coroutine support
 *
 *  From Microsoft Blog:
 *  https://blogs.msdn.microsoft.com/vcblog/2017/05/19/using-c-coroutines-with-boost-c-libraries/
 *
 * Had to add unhandled exception
 *  -- Tal 2017-07-11.
 *
 */

#include <experimental/coroutine>

#define BOOST_THREAD_PROVIDES_FUTURE
#define BOOST_THREAD_PROVIDES_FUTURE_CONTINUATION // Enables future::then
#include <boost/thread.hpp>

#pragma once

// Todo: try to refactor out common code

// Void futures
template <typename... Args>
struct std::experimental::coroutine_traits<boost::future<void>, Args...> {
    struct promise_type {
        boost::promise<void> p;
        auto get_return_object() { return p.get_future(); }
        std::experimental::suspend_never initial_suspend() { return {}; }
        std::experimental::suspend_never final_suspend() { return {}; }
        void set_exception(std::exception_ptr e) { p.set_exception(std::move(e)); }
        void unhandled_exception() { std::terminate(); }
        void return_void() { p.set_value(); }
    };
};

// Non-void futures
template <typename R, typename... Args>
struct std::experimental::coroutine_traits<boost::future<R>, Args...> {
    struct promise_type {
        boost::promise<R> p;
        auto get_return_object() { return p.get_future(); }
        std::experimental::suspend_never initial_suspend() { return {}; }
        std::experimental::suspend_never final_suspend() { return {}; }
        void set_exception(std::exception_ptr e) { p.set_exception(std::move(e)); }
        void unhandled_exception() { std::terminate(); }
        template <typename U> void return_value(U &&u) {
            p.set_value(std::forward<U>(u));
        } 
    }; 
};


