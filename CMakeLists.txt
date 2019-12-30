cmake_minimum_required(VERSION 3.14)
project(dataStructure)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dataStructure
        link/Link.h
        link/main.cpp
        link/test.cpp
        link/test.h stack/calculater.cpp link/test1.cpp stack/tononrecursive.cpp queue/queue.cpp queue/queue.h queue/test.cpp stack/reverseStack.cpp stack/stack.h stack/main.cpp stack/calculater2.cpp stack/deque.cpp)
