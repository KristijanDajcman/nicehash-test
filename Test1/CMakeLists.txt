# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Test1)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Create a variable with the list of source files
file(GLOB SOURCES "src/*.cpp")

# Add the executable target
add_executable(run ${SOURCES})
