
file( GLOB APP_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )
foreach( srcfile ${APP_SRCS} )
    string( REPLACE ".cpp" "" srcname ${srcfile} )
    add_executable( ${srcname} ${srcfile} )
endforeach( srcfile ${APP_SRCS} )

