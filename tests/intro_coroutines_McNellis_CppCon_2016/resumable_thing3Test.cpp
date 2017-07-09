#include <memory>
#include <sstream>

#include "resumable_thing3.hpp"

#include "RedirectStdOut.h"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

extern resumable_thing get_value ();

TEST_CASE ("resumable_thing3Test", "[resumable_thing3")
{
    const std::string captureOutput {
R"(main:     calling get_value
get_value: called
main:     resuming get_value
get_value: resumed
main:     value was: 30
)"
    };

    std::stringstream os {};
    {
        RedirectStdOut rdOut {os};

        std::cout << "main:     calling get_value\n";
        resumable_thing value {get_value () };
        std::cout << "main:     resuming get_value\n";
        value.resume ();
        std::cout << "main:     value was: " << value.get () << "\n";
    }

    CHECK (captureOutput == os.str () );
}

