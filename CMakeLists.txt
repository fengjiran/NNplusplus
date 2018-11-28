cmake_minimum_required(VERSION 3.12)
project(NNplusplus)

set(CMAKE_CXX_STANDARD 14)

add_executable(NNplusplus
        main.cpp
        matrix.hpp
        matrix_exceptions.hpp
        matrix.cpp neural_network.hpp neural_netwok.cpp)