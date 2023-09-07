cmake_minimum_required(VERSION 3.27.3)
project(COEN243FinalProject)
set(CMAKE_CXX_STANDARD 20)
message("\tC++ Standard: ${CMAKE_CXX_STANDARD}")
# CMAKE file for the project
add_executable("COEN243FinalProject" Driver.cpp Employee.h Employee.cpp)
message(STATUS "Adding target for COEN243FinalProject")

add_executable(test test.cpp Employee.h Employee.cpp)

