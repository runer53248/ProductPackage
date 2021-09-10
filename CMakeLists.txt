cmake_minimum_required(VERSION 3.14.0)
set(CMAKE_CXX_STANDARD 20)

project(CostPackager)

add_executable(${PROJECT_NAME} main.cpp Number.cpp NumberPack.cpp Product.cpp)
