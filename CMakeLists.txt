cmake_minimum_required(VERSION 3.15)
project(TodoC VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Cross-platform SQLite setup
find_package(SQLite3 REQUIRED)
include_directories(${SQLite3_INCLUDE_DIRS})

# Source files
add_executable(TodoC src/main.cpp)

# Link SQLite
target_link_libraries(TodoC PRIVATE SQLite::SQLite3)

# Install rules
install(TARGETS TodoC DESTINATION bin)

# Packaging (NSIS for Windows, ZIP for Linux)
set(CPACK_PACKAGE_NAME "TodoC")
set(CPACK_GENERATOR "ZIP")
if(WIN32)
    set(CPACK_GENERATOR "NSIS")
endif()

include(CPack)
