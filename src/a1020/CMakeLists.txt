cmake_minimum_required (VERSION 3.13)

project(a1020 LANGUAGES CXX)

file(GLOB_RECURSE DIR_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.*)

add_executable(a1020 ${DIR_SRCS})
