cmake_minimum_required (VERSION 3.13)

project(t1003 LANGUAGES CXX)

file(GLOB_RECURSE DIR_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.*)

add_executable(t1003 ${DIR_SRCS})
