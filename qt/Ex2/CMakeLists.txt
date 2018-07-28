cmake_minimum_required(VERSION 2.8)

project(Ex2)
# activate latest c++ compiler version
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# set build type to Debug/Release
set(CMAKE_BUILD_TYPE "Debug")
# including all cpp/h files in the current directory
add_executable(${PROJECT_NAME} main.cpp calculater.cpp calculater.h)
