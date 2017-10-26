cmake_minimum_required(VERSION 3.8)
project(RomanTest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp RomanNum.cpp RomanNum.h)
add_executable(RomanTest ${SOURCE_FILES})