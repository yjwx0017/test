add_executable(Test main.cpp)

message("In Test")
message("CMAKE_BINARY_DIR" "\t" ${CMAKE_BINARY_DIR})
message(Test_SOURCE_DIR "\t" ${Test_SOURCE_DIR})
message(CMAKE_CURRENT_BINARY_DIR "\t" ${CMAKE_CURRENT_BINARY_DIR})

set(OUTPUT_DIR "")
get_property(OUTPUT_DIR 
	TARGET Test
	PROPERTY NAME)
message(RUNTIME_OUTPUT_DIRECTORY "\t" ${OUTPUT_DIR})
