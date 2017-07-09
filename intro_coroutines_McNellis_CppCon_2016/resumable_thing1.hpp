/**
 * resumable_thing example: counter
 * From James McNellis: Introduction to C++ Coroutines CppCon 2016.
 */

#include <experimental/coroutine>

#pragma once

/*
 * Added the std::experimental:: qualifications and added unhandled_exception().
 */
struct resumable_thing
{
    struct promise_type
    {
        resumable_thing get_return_object()
        {
            return resumable_thing(std::experimental::coroutine_handle<promise_type>::from_promise (*this) );
        }
        auto initial_suspend() { return std::experimental::suspend_never {}; }
        auto final_suspend() { return std::experimental::suspend_never {}; }
        void unhandled_exception() { std::terminate(); }
        void return_void() {}
    };

    resumable_thing () = default;
    resumable_thing (resumable_thing const&) = delete;
    resumable_thing& operator=(resumable_thing const&) = delete;

    resumable_thing (resumable_thing&& other)
    : _coroutine(other._coroutine) {
        other._coroutine = nullptr;
    }

    resumable_thing& operator = (resumable_thing&& other) {
        if (&other != this) {
            _coroutine = other._coroutine;
            other._coroutine = nullptr;
        }

        return *this;
    }

    explicit resumable_thing (std::experimental::coroutine_handle<promise_type> coroutine)
    : _coroutine {coroutine}
    { }

    ~resumable_thing()
    {
        if (_coroutine) { _coroutine.destroy(); }
    }

    void resume() { _coroutine.resume(); }

    std::experimental::coroutine_handle<promise_type> _coroutine = nullptr;
    
};

