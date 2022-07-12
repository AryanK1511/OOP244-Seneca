cmake_minimum_required(VERSION 3.22)
project(lab)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab
        main.cpp
        MemberParliament.cpp
        MemberParliament.h
        Minister.cpp
        Minister.h)
