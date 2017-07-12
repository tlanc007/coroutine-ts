cmake_minimum_required(VERSION 3.8)

add_definitions(-std=c++14 -fcoroutines-ts)

Include(ExternalProject)
ExternalProject_Add(
    gsl
    PREFIX ${CMAKE_BINARY_DIR}/gsl
    #PREFIX ${CMAKE_INSTALL_PREFIX}/gsl
    GIT_REPOSITORY https://github.com/Microsoft/GSL.git
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
)
ExternalProject_Get_Property(gsl source_dir)
set(GslIncludeDir ${source_dir}/include)

include_directories(${GslIncludeDir})

file( GLOB APP_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )
foreach( srcfile ${APP_SRCS} )
    string( REPLACE ".cpp" "" srcname ${srcfile} )
    include_directories (include)
    add_executable( ${srcname} ${srcfile} )
endforeach( srcfile ${APP_SRCS} )

add_subdirectory(intro_coroutines_McNellis_CppCon_2016)
add_subdirectory(Coroutines_in_Cpp17_CppNow_2015)
add_subdirectory(boost_ms)

Include(ExternalProject)
ExternalProject_Add(
    catch
    PREFIX ${CMAKE_BINARY_DIR}/catch
    URL https://github.com/philsquared/Catch/releases/download/v1.9.6/catch.hpp
    URL_MD5 6e3c2c7dd06d31ae9112b3816da24712
    DOWNLOAD_NO_EXTRACT ON
    DOWNLOAD_DIR ${CMAKE_BINARY_DIR}/catch/src/catch
    ##LOG_DOWNLOAD ON
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(catch source_dir)
set(CatchIncludeDir ${source_dir})

## tests
enable_testing()
add_subdirectory(tests)
