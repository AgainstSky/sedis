cmake_minimum_required(VERSION 3.29)
project(sedis)

set(CMAKE_CXX_STANDARD 17)

add_executable(sedis src/main.cpp
        src/SdsHdr.cpp
        src/SdsHdr.h)
