cmake_minimum_required(VERSION 3.30)

# 2. Set the standard BEFORE the project call so the compiler is probed correctly
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

# 3. Now initialize the project
project(learn_cpp LANGUAGES CXX)


add_executable(
        learn_cpp
        main.cpp
)