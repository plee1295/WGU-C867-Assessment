cmake_minimum_required(VERSION 3.15)
project(C867Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(C867Project
        degree.h
        networkStudent.cpp
        networkStudent.h
        roster.cpp
        roster.h
        securityStudent.cpp
        securityStudent.h
        softwareStudent.cpp
        softwareStudent.h
        student.cpp
        student.h)
