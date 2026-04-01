cmake_minimum_required(VERSION 4.1)
project(ccwc LANGUAGES CXX)

find_package(CLI11 REQUIRED)

add_executable(ccwc src/main.cpp src/wc_utils.cpp)
target_link_libraries(ccwc PRIVATE CLI11::CLI11)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(ccwc PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
set_target_properties(ccwc PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED YES)
