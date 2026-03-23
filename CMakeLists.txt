cmake_minimum_required(VERSION 3.16)

project(learn_cpp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        learn_cpp
        main.cpp
        ByteRing/ByteRing.h
)