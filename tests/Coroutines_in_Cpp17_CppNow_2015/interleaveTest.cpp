#include <memory>
#include <sstream>

#include <gsl/gsl>

#include "RangeOfRanges.hpp"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

TEST_CASE ("resumable_thing3Test", "[resumable_thing3]")
{
    const std::string captureOutput {
R"( 1 10 100 2 20 200 3 30 300 4 40 400 5 50 6 7 8 9
)"
    };

    std::vector <int> a {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector <int> b {10, 20, 30, 40, 50};
    std::vector <int> c {100, 200, 300, 400};

    using T = std::remove_reference_t<decltype (*(std::begin(c) ) )>;
    std::vector <gsl::span<T> > rng {gsl::make_span (a), gsl::make_span (b), gsl::make_span (c) };
    std::stringstream os {};

    for (const auto& e: interleaveCoroutine (rng) ) {
        os << ' ' << e;
    }
    os << '\n';

    CHECK (captureOutput == os.str () );
}


