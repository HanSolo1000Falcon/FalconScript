cmake_minimum_required(VERSION 4.1)
project(falcon_script)

set(CMAKE_CXX_STANDARD 26)

add_executable(FalconScript src/main.cpp
        src/scanner.hpp
        src/token-type.hpp
        src/token.hpp)
