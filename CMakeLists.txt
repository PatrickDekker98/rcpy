cmake_minimum_required(VERSION 3.10)

PROJECT(rcpy CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(include)
add_subdirectory(src)

add_executable(rcpy main.cpp)

target_link_libraries(rcpy rcpy_lib)

