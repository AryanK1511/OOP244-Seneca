cmake_minimum_required(VERSION 3.22)
project(lab)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab
        Account.cpp
        Account.h
        Allocator.cpp
        ChequingAccount.cpp
        ChequingAccount.h
        iAccount.h
        main.cpp
        SavingsAccount.cpp
        SavingsAccount.h)
