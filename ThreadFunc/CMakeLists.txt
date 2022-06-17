cmake_minimum_required(VERSION 3.5)

project(ThreadFunc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ThreadFunc main.cpp ClassThread.h)
