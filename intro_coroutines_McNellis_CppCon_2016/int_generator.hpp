/**
 * generator example: int_generator
 * From James McNellis: Introduction to C++ Coroutines CppCon 2016.
 *
 * Tal Lancaster 2017-07-01
 *   moved out to include file: tal 2017-07-08.
 **/
#pragma once 

#include <experimental/coroutine>

struct int_generator {
    struct promise_type {
        int_generator get_return_object () {
            //return int_generator (std::experimental::coroutine_handle <promise_type>::from_promise (*this) );
            return int_generator (this);
        }

        auto initial_suspend() { return std::experimental::suspend_always {}; }
        auto final_suspend() { return std::experimental::suspend_always {}; }

        void unhandled_exception() { std::terminate(); }
        void return_void() {}

        auto yield_value (int const& value) {
            _current = &value;
            return std::experimental::suspend_always {};
        }

        int const* _current;
    };

    int_generator (int_generator&& rhs)
    : _coroutine {rhs._coroutine}
    {
        rhs._coroutine = nullptr;
    }

    struct iterator: std::iterator <std::input_iterator_tag, int>
    {
        iterator () = default;
        iterator (std::experimental::coroutine_handle <promise_type> coroutine)
        : _coroutine {coroutine}
        { }

        iterator& operator++()
        {
            _coroutine.resume ();
            if (_coroutine.done () ) { _coroutine = nullptr; }
            return *this;
        }

        int const& operator*() const {
            return *_coroutine.promise ()._current;
        }

        bool operator!=(iterator const &_Right) const { return (_coroutine != _Right._coroutine); }

        std::experimental::coroutine_handle <promise_type> _coroutine;
    };

    iterator begin () {
        if (_coroutine) {
            _coroutine.resume ();
            if (_coroutine.done () ) {return end (); }
        }

        return iterator (_coroutine);
    }

    iterator end () {return iterator {}; }

private:
   explicit int_generator (promise_type* coroutine)
    : _coroutine {std::experimental::coroutine_handle<promise_type>::from_promise(*coroutine) } {}

    std::experimental::coroutine_handle <promise_type> _coroutine;

};

