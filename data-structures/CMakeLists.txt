cmake_minimum_required(VERSION 3.15)

# Project name
project(MyProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define project directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)

# Include the header files directory
include_directories(${INCLUDE_DIR})

# Find Catch2 for testing
find_package(Catch2 3 REQUIRED)

# Gather source files for testing
file(GLOB SRC_FILES "${SRC_DIR}/*.cc")
file(GLOB TEST_FILES "${TEST_DIR}/*.cc")

# Combine source and test files
set(TEST_SOURCES ${SRC_FILES} ${TEST_FILES})

# Add a testing target
add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES})

# Link Catch2 with the test executable
target_link_libraries(${PROJECT_NAME}_tests PRIVATE Catch2::Catch2)

# Enable testing with Catch2
include(CTest)
include(Catch)
catch_discover_tests(${PROJECT_NAME}_tests)
