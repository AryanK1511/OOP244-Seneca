cmake_minimum_required(VERSION 3.22)
project(MS3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MS3
        Date.cpp
        Date.h
        Lib.h
        ms3_tester.cpp
        Publication.cpp
        Publication.h
        Streamable.cpp
        Streamable.h
        Utils.cpp
        Utils.h)
