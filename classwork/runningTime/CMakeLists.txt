cmake_minimum_required(VERSION 3.27)
project(runningTime)

set(CMAKE_CXX_STANDARD 17)

add_executable(runningTime running_time_of_sort.cpp
        timer.h)
