

#include_directories(${CatchIncludeDir} ${PROJECT_SOURCE_DIR})

add_definitions(-DAS_TEST)

##add_dependency(catch catch.hpp )

set(SRC_PATH ${PROJECT_SOURCE_DIR}/intro_coroutines_McNellis_CppCon_2016)

set(TEST_NAME int_generatorTest)
include_directories(${SRC_PATH} ../include)

add_executable( ${TEST_NAME} int_generatorTest.cpp ${SRC_PATH}/int_generator.cpp)
add_test( NAME ${TEST_NAME}
    COMMAND ${TEST_NAME})

set(TEST_NAME resumable_thing1Test)
add_executable( ${TEST_NAME} resumable_thing1Test.cpp ${SRC_PATH}/resumable_thing1.cpp)
add_test( NAME ${TEST_NAME}
    COMMAND ${TEST_NAME})


