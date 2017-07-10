
#find_package(GSL REQUIRED)
#target_link_libraries(GSL::GSL)

remove_definitions(-std=c++14)
add_definitions(-std=c++1y)

file( GLOB APP_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )
foreach( srcfile ${APP_SRCS} )
    string( REPLACE ".cpp" "" srcname ${srcfile} )
    add_executable( ${srcname} ${srcfile} )
    add_dependencies(${srcname} catch )
endforeach( srcfile ${APP_SRCS} )

