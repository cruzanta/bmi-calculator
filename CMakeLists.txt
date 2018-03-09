cmake_minimum_required(VERSION 3.9.1)
project(BMIcalculator)

# Headers
include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

file(GLOB_RECURSE bmi-calculator_SOURCES "src/*.cpp")

add_executable(BMIcalculator ${bmi-calculator_SOURCES})
