cmake_minimum_required(VERSION 3.10)

project(TDM)

add_library(TDM STATIC TDM.cpp)
target_include_directories(TDM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)