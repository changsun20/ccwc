cmake_minimum_required(VERSION 4.1)
project(ccwc LANGUAGES CXX)

find_package(CLI11 REQUIRED)
find_package(Catch2 3 REQUIRED)

add_library(wc_utils src/wc_utils.cpp)

add_executable(ccwc src/main.cpp)
target_link_libraries(ccwc PRIVATE CLI11::CLI11 wc_utils)

add_executable(tests tests/test_wc.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain wc_utils)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(ccwc PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
set_target_properties(ccwc PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED YES)
