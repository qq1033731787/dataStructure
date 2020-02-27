cmake_minimum_required(VERSION 3.14)
project(dataStructure)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(./googletest)
include_directories(./link ./googletest/googletest/include ./stack ./queue . ./string)
link_directories(./googletest ./cmake-build-debug/lib)


add_executable(dataStructure
             Tree/main.cpp)
target_link_libraries(dataStructure gtest pthread)