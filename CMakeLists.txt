cmake_minimum_required(VERSION 4.1)
project(ccwc LANGUAGES CXX)

find_package(CLI11 REQUIRED)

add_executable(ccwc src/main.cpp)
target_link_libraries(ccwc PRIVATE CLI11::CLI11)
