

#include_directories(${CatchIncludeDir} ${PROJECT_SOURCE_DIR})

add_definitions(-DAS_TEST)

##add_dependency(catch catch.hpp )

set(TEST_NAME int_generatorTest)
set(SRC_PATH ${PROJECT_SOURCE_DIR}/intro_coroutines_McNellis_CppCon_2016)
include_directories(${SRC_PATH})

add_executable( ${TEST_NAME} int_generatorTest.cpp ${SRC_PATH}/int_generator.cpp)
add_test( NAME ${TEST_NAME}
    COMMAND ${TEST_NAME})

#set(TEST_NAME fibonacciGenTest)
#add_executable( ${TEST_NAME} fibonacciGenTest.cpp ../fibonacciGen.cpp)
#add_test( NAME ${TEST_NAME}
#    COMMAND ${TEST_NAME})


