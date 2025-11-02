cmake_minimum_required(VERSION 3.15)
project(TodoC VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Source files
add_executable(TodoC src/main.cpp)

# Install rules
install(TARGETS TodoC DESTINATION bin)

include(CPack)
