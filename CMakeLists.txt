cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Enable recursive search in subdirectories
file(GLOB_RECURSE ALL_SUBDIRS RELATIVE ${CMAKE_SOURCE_DIR} */src)

# Add subdirectories for each submodule
add_subdirectory(day1)
add_subdirectory(day2)