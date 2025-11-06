cmake_minimum_required (VERSION 3.13)

project(a1025 LANGUAGES CXX)

file(GLOB_RECURSE DIR_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.*)

add_executable(a1025 ${DIR_SRCS})
