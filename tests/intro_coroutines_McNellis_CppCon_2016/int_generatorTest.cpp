#include <memory>
#include <sstream>

#include <memory>
#include <sstream>

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "int_generator.hpp"

extern int_generator integers (int first, int last);

TEST_CASE ("int_generator", "[int_generator]")
{
    const std::string capturedOutput {
R"( 1 2 3 4 5
)"
    };

    std::stringstream os {};
    for (auto x: integers (1, 5) ) {
        os << ' ' << x;
    }
    os << '\n';

    CHECK (capturedOutput == os.str () );
}


