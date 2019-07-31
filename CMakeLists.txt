cmake_minimum_required(VERSION 3.13)
project(EmployeeManagementSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(ems src/EMS.cpp src/EmployeeManager.cpp header/EmployeeManager.h)