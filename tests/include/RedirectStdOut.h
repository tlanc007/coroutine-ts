/**
 class to redirect std::cout to a stringstream
 
 The issue was the code from APIBook.com wrote examples to
 std::cout and the desire was to do integration tests against
 the programs.  So this was the least intrusive way to deal with
 the grabbing the output for comparision.
 **/

#pragma once
#include <iostream>
#include <sstream>

class RedirectStdOut {
public:
    explicit RedirectStdOut (std::streambuf* newBuffer)
    : orig {std::cout.rdbuf (newBuffer) }
    { }

    explicit RedirectStdOut (std::stringstream& stream)
    : orig {std::cout.rdbuf (stream.rdbuf () ) }
    { }

    ~RedirectStdOut () {
        std::cout.rdbuf (orig);
    }
    
private:
    std::streambuf* orig;
};
