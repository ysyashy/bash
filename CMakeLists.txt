# cmake_minimum_required(VERSION 3.8)
project(bash)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Execute.cpp Execute.h Arguments.cpp Arguments.h public_header.h)
add_executable(bash ${SOURCE_FILES})
