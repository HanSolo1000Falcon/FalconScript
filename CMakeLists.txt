cmake_minimum_required(VERSION 4.1)
project(falcon_script)

set(CMAKE_CXX_STANDARD 26)

set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

add_executable(FalconScript src/main.cpp
        src/scanner.cpp
        src/executor.cpp
)
