
#set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/scripts/ )
#set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/scripts/ )

include_directories(${CatchIncludeDir} ${PROJECT_SOURCE_DIR})

add_definitions(-DAS_TEST)


set(TEST_NAME numberGenTest)
set(SRC_PATH ${TOP_SRC_PATH})
add_executable( ${TEST_NAME} numberGenTest.cpp ../numberGen.cpp)
add_test( NAME ${TEST_NAME}
    COMMAND ${TEST_NAME})
add_dependencies(${TEST_NAME} catch )

set(TEST_NAME fibonacciGenTest)
add_executable( ${TEST_NAME} fibonacciGenTest.cpp ../fibonacciGen.cpp)
add_test( NAME ${TEST_NAME}
    COMMAND ${TEST_NAME})
add_dependencies(${TEST_NAME} catch )

add_subdirectory(intro_coroutines_McNellis_CppCon_2016)
add_subdirectory(Coroutines_in_Cpp17_CppNow_2015)
add_subdirectory(boost_ms)
