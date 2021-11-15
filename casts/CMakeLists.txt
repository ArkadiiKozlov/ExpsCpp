cmake_minimum_required(VERSION 3.5)

project(casts LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(casts main.cpp exp_dyn_static_cast.cpp)
