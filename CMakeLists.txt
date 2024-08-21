cmake_minimum_required(VERSION 3.29)
project(cppStudentGradesSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(cppStudentGradesSystem main.cpp
        student.hpp
        BellCurve.hpp
)
