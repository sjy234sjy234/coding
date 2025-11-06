cmake_minimum_required (VERSION 3.13)

project(b1036 LANGUAGES CXX)

file(GLOB_RECURSE DIR_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.*)

add_executable(b1036 ${DIR_SRCS})
