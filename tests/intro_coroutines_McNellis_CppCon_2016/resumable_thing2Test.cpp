#include <memory>
#include <sstream>

#include "resumable_thing1.hpp"

#include "RedirectStdOut.h"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

extern resumable_thing named_counter (std::string name);

TEST_CASE ("resumable_thing2Test", "[resumeable_thing2]")
{
    const std::string captureOutput {
R"(counter(a) was called
counter(b) was called
counter(a) resumed # 1
counter(b) resumed # 1
counter(b) resumed # 2
counter(a) resumed # 2
)"
    };

    std::stringstream os {};
    {
        RedirectStdOut rdOut {os};

        resumable_thing counter_a {named_counter ("a") };
        resumable_thing counter_b {named_counter ("b") };
        counter_a.resume ();
        counter_b.resume ();
        counter_b.resume ();
        counter_a.resume ();
    }

    CHECK (captureOutput == os.str () );
}

