#include <memory>
#include <sstream>

#include "generator.hpp"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

generator <unsigned long> numGen (unsigned long n)
{
    for (auto i {0ul}; i < n; ++i) {
        co_yield i;
    }
}

TEST_CASE ("numberGenTest", "[numberGen]")
{
    const std::string capturedOutput {
R"(0
1
2
3
4
)"
    };

    std::stringstream os {};
    for (auto e: numGen (5) ) {
        os << e << "\n";
    }

    CHECK (capturedOutput == os.str () );
}

