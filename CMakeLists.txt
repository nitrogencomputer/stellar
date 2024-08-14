cmake_minimum_required(VERSION 3.14)
project(nitrogen_stellar C CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(nitrogen_stellar src/stellar.cpp src/stellar.hpp)