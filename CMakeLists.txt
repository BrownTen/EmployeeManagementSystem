cmake_minimum_required(VERSION 3.13)
project(EmployeeManagementSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(test test/Test.cpp  header/Employee.h src/Staff.cpp header/Staff.h src/Manager.cpp header/Manager.h src/Boss.cpp header/Boss.h)
add_executable(ems src/EMS.cpp src/EmployeeManager.cpp header/EmployeeManager.h header/Employee.h src/Staff.cpp header/Staff.h src/Manager.cpp header/Manager.h src/Boss.cpp header/Boss.h)