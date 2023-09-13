cmake_minimum_required(VERSION 3.27.3)
project(COEN243FinalProject)
set(CMAKE_CXX_STANDARD 20)
message("\t\tC++ Standard: ${CMAKE_CXX_STANDARD}")
# CMAKE file for the project
add_executable("SchoolSystem" src/Employee.h src/Employee.cpp src/Driver.cpp)
message(STATUS "University Students&Staff Database")



