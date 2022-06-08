cmake_minimum_required(VERSION 3.22)
project(kursovya)

set(CMAKE_CXX_STANDARD 14)

add_executable(kursovya main.cpp Student.cpp Student.h function.h)
