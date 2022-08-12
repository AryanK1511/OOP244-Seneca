cmake_minimum_required(VERSION 3.22)
project(MS5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MS5
        Book.cpp
        Book.h
        Date.cpp
        Date.h
        Lib.h
        LibApp.cpp
        LibApp.h
        LibAppMain.cpp
        Menu.cpp
        Menu.h
        Publication.cpp
        Publication.h
        PublicationSelector.cpp
        PublicationSelector.h
        Streamable.cpp
        Streamable.h
        Utils.cpp
        Utils.h)
