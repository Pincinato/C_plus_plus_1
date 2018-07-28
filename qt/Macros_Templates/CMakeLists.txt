cmake_minimum_required(VERSION 2.8)
# activate latest c++ compiler version
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# set build type to Debug/Release
set(CMAKE_BUILD_TYPE "Debug")
project(Macros_Templates)
add_executable(${PROJECT_NAME} "main.cpp")
