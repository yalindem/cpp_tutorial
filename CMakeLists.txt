cmake_minimum_required(VERSION 3.10)

project(MyProject LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the executable
add_executable(main src/main.cpp)