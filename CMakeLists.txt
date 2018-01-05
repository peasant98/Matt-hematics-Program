cmake_minimum_required(VERSION 3.9)
project(KingSoopers)

set(CMAKE_CXX_STANDARD 11)

add_executable(KingSoopers main.cpp Mathematics.cpp Mathematics.h in.txt out.txt)
