#Intro to coroutines McNellis_CppCon_2016
Examples from James McNellis **Introdution to Coroutines at CppCon 2016**.

# Background
The following are some of the exampes for the talk: [Introduction to Coroutines CppCon 2016](https://www.youtube.com/watch?v=ZTqHjjm86Bw).  The slides for this talk are missing from the [CppCon2016](https://github.com/CppCon/CppCon2016) repo on **github**.  However, I found [these slides](https://meetingcpp.com/tl_files/mcpp/2015/talks/James%20McNellis%20-%20Coroutines%20-%20%20Meeting%20C++%202015.pdf) a close substutute on meettingcpp.com.

The examples were tweaked a little to get them to compile and for clang++ 5.

# Examples
## compiler command line
```
clang++ -std=c++14 -fcoroutines-ts -stdlib=libc++ blah.cpp
```
The typical command-line options one will want are: `-fcoroutines-ts` `-stdlib=libc++`.  Also I tend to compile the programs either under c++14 or 1z (17): `-std=c++14` or `-std=c++1z`.

## resumable_thing1.cpp
This is the **counter** example.  The output should be:

```
main: calling counter
counter: called
main: resuming counter
counter: resumed (#1)
counter: resumed (#2)
main: done
```


## resumable_thing2.cpp
This is the **named_counter** example.  The output should be:

```
counter(a) was called
counter(b) was called
counter(a) resumed # 1
counter(b) resumed # 1
counter(b) resumed # 2
counter(a) resumed # 2
```
## resumable_thing3.cpp
This is the **get_value** example.  The output should be:

```
main:     calling get_value
get_value: called
main:     resuming get_value
get_value: resumed
main:     value was: 30
```

## int_generator.cpp
This is the **generator** example.  Note: a more generalzied example of generator type is found in `generator.hpp` in the top directory.

The output should be:

```
1 2 3 4 5
```

