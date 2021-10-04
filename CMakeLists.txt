cmake_minimum_required(VERSION 3.20)
project(oop_lab_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop_lab_1 src/main.cpp include/record.h src/record.cpp src/journal.cpp include/journal.h)
