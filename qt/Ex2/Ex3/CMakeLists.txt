cmake_minimum_required(VERSION 2.8)

project(Ex3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
# set build type to Debug/Release
set(CMAKE_BUILD_TYPE "Debug")
add_executable(${PROJECT_NAME} main.cpp monteCarlo.h montecarlo.cpp)
