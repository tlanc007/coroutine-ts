# coroutine-ts
misc. notes on C++ experimental coroutine under clang/llvm 5

# Background
With clang/llvm 5.0 there is support for the experimental coroutines.  But it has been difficult finding proper examples using coroutines under this compiler.

The following are my notes on what I have done to get some examples to work using the experimental/coroutine header file.

The repo makes use of CMake to set up the build environment.

# Dependencies
  * gsl -- for the Coroutines in Cpp17 examples 
    * CMake will download it for you
  * Catch -- for the tests folder
    * CMake will download it for you
  * Boost 1.60.0 -- for the boost_ms folder
     * You will need to manually download and install this yourself.

# Examples

## compiler command line
```
clang++ -std=c++14 -fcoroutines-ts -stdlib=libc++ blah.cpp
```
The typical command-line options one will want are: `-fcoroutines-ts` `-stdlib=libc++`.  Also I tend to compile the programs either under c++14 or 1z (17): `-std=c++14` or `-std=c++1z`.

## generator.h
In scouring for examples, I did come across several examples of a **generator.h**.  But when I tried using them, I would get compiler warnings like:

```
error: 'promise_type' is required to declare the
      member 'unhandled_exception()'
```

Also I had to compile with `-fno-exceptions` option.  This has the obvious side effect that prevents one from compiling code that is using making use of exceptions.

The missing line that was needed to be able to work with exceptions and discard the `-fno-exceptions` option was:

```
 void unhandled_exception() { std::terminate(); }
```

Now, I can build examples using this **generator.h** file.

## Simple number generator
**numberGen.cpp**: is a simple example of a number generator.

Compile:
```
% clang++ -std=c++14 -fcoroutines-ts -stdlib=libc++ numberGen.cpp
```

Output:

```
0
1
2
3
4
```

### Fibonacci Generator with sentinel
**fibonacciGen.cpp**: an infinite fibonacci generator.  This example uses a sentinel to stop after a number of iterations have been called.  Also, the function is iterative rather than recursive.  It takes advantage of the previous state of the function call to compute the next number on the fly.

Compile:
```
clang++ -std=c++14 -fcoroutines-ts -stdlib=libc++ fibonacciGen.cpp
```

Output: (10 iterations)

```
1
1
2
3
5
8
13
21
34
55
```   

## Introduction to coroutines CppCon 2016
Under the directory `intro_coroutines_McNellis_CppCon_2016` are a number of examples that were built up during the presentation.  More information can be found in that directory's [ReadMe](https://github.com/tlanc007/coroutine-ts/blob/master/intro_coroutines_McNellis_CppCon_2016/Readme.md).

## Coroutines in Cpp17 CppNow 2017
Under the directory `Coroutines_in_Cpp17_CppNow_2015` are a number of examples from Gor Nishanov.


## Boost Microsoft Blog
 Under the directory `boost_ms` are a number of examples that were posted in a Microsoft blog about using Boost and coroutines.  

**NOTE:** you will need to have at least Boost 1.60.0 installed to run these examples.
 
More information can be found in that directory's [ReadMe](https://github.com/tlanc007/coroutine-ts/blob/master/boost_ms/ReadMe.md).