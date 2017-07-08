#include <memory>
#include <sstream>

#include "generator.hpp"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

extern generator <unsigned long> numGen (unsigned long n);

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
    for (const auto& e: numGen (5) ) {
        os << e << "\n";
    }

    CHECK (capturedOutput == os.str () );
}

