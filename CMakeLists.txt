cmake_minimum_required(VERSION 3.12)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Calculator main.cpp)

add_subdirectory(./lib/googletest-master)

add_executable(tests ./lib/main_tests.cpp)

target_include_directories(tests PUBLIC ./lib/googletest-master/include)

target_link_libraries(tests gtest gtest_main)

get_target_property(TESTS_COMPILE_FLAGS tests COMPILE_FLAGS)
if(TESTS_COMPILE_FLAGS STREQUAL "TESTS_COMPILE_FLAGS-NOTFOUND")
    SET(TESTS_COMPILE_FLAGS "")
else()
    SET(TESTS_COMPILE_FLAGS "${TESTS_COMPILE_FLAGS} ")
endif()
SET(TESTS_COMPILE_FLAGS "${TESTS_COMPILE_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage" )
set_target_properties(tests PROPERTIES COMPILE_FLAGS ${TESTS_COMPILE_FLAGS} )

get_target_property(TESTS_LINK_FLAGS tests LINK_FLAGS)
if(TESTS_LINK_FLAGS STREQUAL "TESTS_LINK_FLAGS-NOTFOUND")
    SET(TESTS_LINK_FLAGS "")
else()
    SET(TESTS_LINK_FLAGS "${TESTS_LINK_FLAGS} ")
endif()
SET(TESTS_LINK_FLAGS "${TESTS_LINK_FLAGS} -lgcov --coverage" )
set_target_properties(tests PROPERTIES LINK_FLAGS ${TESTS_LINK_FLAGS} )
