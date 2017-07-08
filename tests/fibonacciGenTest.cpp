#include <memory>
#include <sstream>

#include "generator.hpp"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

extern generator <unsigned long> fibGen ();
extern generator <unsigned long> take_until (generator <unsigned long>& g, size_t sentinel);


TEST_CASE ("fibonacciGenTest", "[fibonacciGenTest]")
{
    const std::string capturedOutput {
R"(1
1
2
3
5
8
13
21
34
55
)"
    };

    constexpr auto Sentinel {10ul};
    auto g {fibGen () };
    auto t {take_until (g, Sentinel) };

    std::stringstream os {};
    for (const auto& e: t) {
        os << e << "\n";
    }

    CHECK (capturedOutput == os.str () );
}

