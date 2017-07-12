
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
target_link_libraries( ${srcname} ${Boost_LIBRARIES} )
endforeach( srcfile ${APP_SRCS} )
