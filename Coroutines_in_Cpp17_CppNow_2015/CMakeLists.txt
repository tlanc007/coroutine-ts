
#find_package(GSL REQUIRED)
#target_link_libraries(GSL::GSL)

Include(ExternalProject)
ExternalProject_Add(
    gsl
    PREFIX ${CMAKE_BINARY_DIR}/gsl
    #PREFIX ${CMAKE_INSTALL_PREFIX}/gsl
    #GIT_REPOSITORY https://github.com/Microsoft/GSL.git
    GIT_REPOSITORY /Volumes/users/tal/Downloads/gsl
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    #INSTALL_COMMAND ${CMAKE_COMMAND} -E copy_directory
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
)
ExternalProject_Get_Property(gsl source_dir)
set(GslIncludeDir ${source_dir}/include)

include_directories(${GslIncludeDir})

remove_definitions(-std=c++14)
add_definitions(-std=c++1y)

file( GLOB APP_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )
foreach( srcfile ${APP_SRCS} )
    string( REPLACE ".cpp" "" srcname ${srcfile} )
    add_executable( ${srcname} ${srcfile} )
endforeach( srcfile ${APP_SRCS} )

