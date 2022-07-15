cmake_minimum_required(VERSION 3.22)
project(ms2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ms2
        LibApp.cpp
        LibApp.h
        Menu.cpp
        Menu.h
        ms2_tester.cpp
        Utils.cpp
        Utils.h)
