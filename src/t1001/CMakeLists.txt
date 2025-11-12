cmake_minimum_required (VERSION 3.13)

project(t1001 LANGUAGES CXX)

file(GLOB_RECURSE DIR_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.*)

add_executable(t1001 ${DIR_SRCS})
