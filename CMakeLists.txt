cmake_minimum_required(VERSION 3.10)
project(chess_bot)

set(CMAKE_CXX_STANDARD 17)

# Find all .cpp files in the src/ directory
file(GLOB SRC_FILES "src/*.cpp")

# Add executable with all source files
add_executable(chess_bot ${SRC_FILES})

# Include directories
include_directories(include)

# Place executable in project root
set_target_properties(chess_bot PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})