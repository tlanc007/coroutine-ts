#Coroutines in Cpp17 CppNow 2015
Examples from Gor Nishanov's talk **Coroutines in C++17 at CppNow 2015**.

#Background
The following are some of the examples for the talk [Coroutines in C++17 at CppNow 2015]().

#Examples

## interleaveOrig.cpp
This example is provided for historical reference.  Today we would use span to deal with the ranges rather than build up a type like the Range_t.  There is another version below that implements the example with `gsl::span`.

## interleave.cpp
This is a variant of the interleave that Gor presented.  This version is making use of `gsl::span` instead of the custom Range_t class.

## interleaveNonTemplate.cpp
This is similar to the interleave example.  The difference is that it is hardcoded to using int rather than the more generic template version found in interleave.cpp.  It doesn't have the distractions of dealing with a template version to more directly show the example.

