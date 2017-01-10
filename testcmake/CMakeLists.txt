cmake_minimum_required(VERSION 2.6)

project(testCMake)

set(VAR test_string)
message(${VAR})
message("${VAR}")
message(Test_SOURCE_DIR "\t" ${Test_SOURCE_DIR})
message(testCMake_SOURCE_DIR "\t" ${testCMake_SOURCE_DIR})
message(CMAKE_BINARY_DIR "\t" ${CMAKE_BINARY_DIR})
message(CMAKE_CURRENT_BINARY_DIR "\t" ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(Test)
