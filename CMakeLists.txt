cmake_minimum_required(VERSION 3.14)
project(nitrogensmart C CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/json/include)  

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

add_executable(nitrogensmart src/main.cpp src/base.cpp src/base.hpp src/stellar/rpc.cpp src/stellar/rpc.hpp) 
target_link_libraries(nitrogensmart ${CURL_LIBRARIES})
