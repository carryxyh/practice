cmake_minimum_required(VERSION 3.8)
project(practice)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES vector.cpp
        Sales_data.h)
add_executable(practice ${SOURCE_FILES})