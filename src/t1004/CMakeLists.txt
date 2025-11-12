cmake_minimum_required (VERSION 3.13)

project(t1004 LANGUAGES CXX)

file(GLOB_RECURSE DIR_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.*)

add_executable(t1004 ${DIR_SRCS})
