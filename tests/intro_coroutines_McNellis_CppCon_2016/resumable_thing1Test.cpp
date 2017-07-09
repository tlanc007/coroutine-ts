#include <memory>
#include <sstream>

#include "resumable_thing1.hpp"

#include "RedirectStdOut.h"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

extern resumable_thing counter ();

TEST_CASE ("resumable_thing1Test", "[resumable_thing1]")
{
    const std::string captureOutput {
R"(main: calling counter
counter: called
main: resuming counter
counter: resumed (#1)
counter: resumed (#2)
main: done
)"
    };

    std::stringstream os {};
    {
        RedirectStdOut rdOut {os};

        std::cout << "main: calling counter\n";
        resumable_thing the_counter {counter () };
        std::cout << "main: resuming counter\n";

        the_counter.resume ();
        the_counter.resume ();

        std::cout << "main: done\n";
    }

    CHECK (captureOutput == os.str () );
}


