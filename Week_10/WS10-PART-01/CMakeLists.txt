cmake_minimum_required(VERSION 3.22)
project(lab)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab
        Book.cpp
        Book.h
        Card.cpp
        Card.h
        Collection.h
        main.cpp
        Pet.cpp
        Pet.h
        templateFunctions.h
        Write.cpp
        Write.h)
