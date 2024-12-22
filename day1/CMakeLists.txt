# Enable testing for this module
enable_testing()


# Automatically collect all .cpp files in the src folder
file(GLOB MODULE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# Remove Day1Main.cpp from the MODULE_SOURCES for the test build
list(REMOVE_ITEM MODULE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/Day1Main.cpp)

# Create a static library for the day1 logic
add_library(day1_lib STATIC ${MODULE_SOURCES})

# Add the directory containing the header files for the main executable
target_include_directories(day1_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Create the main executable
get_filename_component(EXECUTABLE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_executable(${EXECUTABLE_NAME} ${MODULE_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/src/Day1Main.cpp)
target_link_libraries(day1 day1_lib)


# Create the test executable for day1
file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp)
add_executable(day1_tests ${TEST_SOURCES})

# Link googletest to the test executable
target_link_libraries(day1_tests gtest gtest_main day1_lib)

# Link the main source files to the test executable if needed
target_include_directories(day1_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${googletest_SOURCE_DIR}/googletest/include
)

# Register the test executable with CTest
add_test(NAME day1_tests COMMAND day1_tests)
