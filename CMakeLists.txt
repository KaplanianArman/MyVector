cmake_minimum_required(VERSION 3.24)
project(MyVector LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_subdirectory(lib)
add_subdirectory(bin)