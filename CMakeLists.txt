cmake_minimum_required (VERSION 3.13)

project (coding LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fopenmp")

add_subdirectory(src/coding)

add_subdirectory(src/a1025)

add_subdirectory(src/b1001)
add_subdirectory(src/b1009)
add_subdirectory(src/b1022)
add_subdirectory(src/b1032)
add_subdirectory(src/b1036)
