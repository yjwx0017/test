cmake_minimum_required(VERSION 2.6)

project(Test)

set(VAR test_string)
message(${VAR})
message("${VAR}")
message(${Test_SOURCE_DIR})

add_executable(Test main.cpp)