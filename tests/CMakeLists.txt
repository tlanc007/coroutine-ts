
#set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/scripts/ )
#set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/scripts/ )
LIST(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake/scripts/ )
include(DownloadURL)

# get the released catch header file and not entire repo
#file(DOWNLOAD
#https://github.com/philsquared/Catch/releases/download/v1.9.6/catch.hpp
#${CMAKE_BINARY_DIR}/catch/include
#SHOW_PROGRESS
#)

Include(ExternalProject)
ExternalProject_Add(
    catch
    PREFIX ${CMAKE_BINARY_DIR}/catch
    #URL https://github.com/philsquared/Catch/releases/download/v1.9.6/catch.hpp ${CMAKE_BINARY_DIR}/catch
    URL https://github.com/philsquared/Catch/archive/v1.9.6.tar.gz    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
)

ExternalProject_Get_Property(catch source_dir)
set(CatchIncludeDir ${source_dir}/include)

include_directories(${CatchIncludeDir} ${PROJECT_SOURCE_DIR})

add_definitions(-DAS_TEST)

##add_dependency(catch catch.hpp )
add_executable( numberGenTest numberGenTest.cpp ../numberGen.cpp)
add_test( NAME numberGenTest
    COMMAND numberGenTest)

add_executable( fibonacciGenTest fibonacciGenTest.cpp ../fibonacciGen.cpp)
add_test( NAME fibonacciGenTest
    COMMAND fibanacciGenTest)


