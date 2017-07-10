

#include_directories(${CatchIncludeDir} ${PROJECT_SOURCE_DIR})

add_definitions(-DAS_TEST)

set(SRC_PATH ${PROJECT_SOURCE_DIR}/Coroutines_in_Cpp17_CppNow_2015)

include_directories(${SRC_PATH} ../include)

set(TEST_NAME interleaveTest)

add_executable( ${TEST_NAME} interleaveTest.cpp)
add_test( NAME ${TEST_NAME}
    COMMAND ${TEST_NAME})
add_dependencies(${TEST_NAME} gsl )
add_dependencies(${TEST_NAME} catch )

#[==[
set(TEST_NAME resumable_thing1Test)
add_executable( ${TEST_NAME} resumable_thing1Test.cpp ${SRC_PATH}/resumable_thing1.cpp)
add_test( NAME ${TEST_NAME}
    COMMAND ${TEST_NAME})

set(TEST_NAME resumable_thing2Test)
add_executable( ${TEST_NAME} resumable_thing2Test.cpp ${SRC_PATH}/resumable_thing2.cpp)
add_test( NAME ${TEST_NAME}
COMMAND ${TEST_NAME})

set(TEST_NAME resumable_thing3Test)
add_executable( ${TEST_NAME} resumable_thing3Test.cpp ${SRC_PATH}/resumable_thing3.cpp)
add_test( NAME ${TEST_NAME}
COMMAND ${TEST_NAME})
#]==]

