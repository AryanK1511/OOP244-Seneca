cmake_minimum_required(VERSION 3.22)
project(MS1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MS1
        Menu.cpp
        Menu.h
        ms1_tester.cpp
        Utils.cpp
        Utils.h
        Date.cpp
        Date.h
        )
