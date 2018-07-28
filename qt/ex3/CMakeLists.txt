cmake_minimum_required(VERSION 2.8)

project(ex3)
# activate latest c++ compiler version
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# set build type to Debug/Release
set(CMAKE_BUILD_TYPE "Debug")
# including all cpp/h files in the current directory
add_executable(${PROJECT_NAME} main.cpp ex3.h ex3.cpp ex3_2.h ex3_2.cpp)
