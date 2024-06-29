cmake_minimum_required(VERSION 3.24)
project(ia2048)

set(CMAKE_CXX_STANDARD 17)

add_executable(ia2048 main.cpp game.h game.cpp)
