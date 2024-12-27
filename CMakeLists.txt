cmake_minimum_required(VERSION 3.31)
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Enable testing for the entire project
enable_testing()

# FetchContent for GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0  # You can specify a different version if needed
)
FetchContent_MakeAvailable(googletest)


# Enable recursive search in subdirectories
file(GLOB_RECURSE ALL_SUBDIRS RELATIVE ${CMAKE_SOURCE_DIR} */src)

# Add subdirectories for each submodule
add_subdirectory(day1)
add_subdirectory(day2)
add_subdirectory(day3)
add_subdirectory(day4)
add_subdirectory(day5)
