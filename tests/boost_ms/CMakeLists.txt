

#include_directories(${CatchIncludeDir} ${PROJECT_SOURCE_DIR})

add_definitions(-DAS_TEST)


set(SRC_PATH ${PROJECT_SOURCE_DIR}/boost_ms)

find_package(
    Boost 1.60.0
    REQUIRED
    COMPONENTS thread system exception
)

if (Boost_FOUND)
    include_directories (SYSTEM ${Boost_INCLUDE_DIR} )
endif ()

file( GLOB APP_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )
foreach( srcfile ${APP_SRCS} )
    string( REPLACE ".cpp" "" srcname ${srcfile} )
    add_executable( ${srcname} ${srcfile} )
    add_dependencies(${srcname} catch )
    target_link_libraries( ${srcname} ${Boost_LIBRARIES} )
    add_test (NAME ${srcname}
        COMMAND ${srcname} )
endforeach( srcfile ${APP_SRCS} )

#[==[
set(TEST_NAME int_generatorTest)
include_directories(${SRC_PATH} ../include)

add_executable( ${TEST_NAME} int_generatorTest.cpp ${SRC_PATH}/int_generator.cpp)
add_test( NAME ${TEST_NAME}
    COMMAND ${TEST_NAME})
add_dependencies(${TEST_NAME} catch )

set(TEST_NAME resumable_thing1Test)
add_executable( ${TEST_NAME} resumable_thing1Test.cpp ${SRC_PATH}/resumable_thing1.cpp)
add_test( NAME ${TEST_NAME}
    COMMAND ${TEST_NAME})
add_dependencies(${TEST_NAME} catch )

set(TEST_NAME resumable_thing2Test)
add_executable( ${TEST_NAME} resumable_thing2Test.cpp ${SRC_PATH}/resumable_thing2.cpp)
add_test( NAME ${TEST_NAME}
COMMAND ${TEST_NAME})
add_dependencies(${TEST_NAME} catch )

set(TEST_NAME resumable_thing3Test)
add_executable( ${TEST_NAME} resumable_thing3Test.cpp ${SRC_PATH}/resumable_thing3.cpp)
add_test( NAME ${TEST_NAME}
COMMAND ${TEST_NAME})
add_dependencies(${TEST_NAME} catch )
#]==]
