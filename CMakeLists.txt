cmake_minimum_required(VERSION 3.3)

add_definitions(-std=c++14 -fcoroutines-ts)

file( GLOB APP_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )
foreach( srcfile ${APP_SRCS} )
    string( REPLACE ".cpp" "" srcname ${srcfile} )
    add_executable( ${srcname} ${srcfile} )
endforeach( srcfile ${APP_SRCS} )

add_subdirectory(intro_coroutines_McNellis_CppCon_2016)
add_subdirectory(Coroutines_in_Cpp17_CppNow_2015)
