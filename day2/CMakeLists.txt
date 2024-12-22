# Enable testing for this module
enable_testing()


# Automatically collect all .cpp files in the src folder
file(GLOB MODULE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# Remove day2Main.cpp from the MODULE_SOURCES for the test build
list(REMOVE_ITEM MODULE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/Day2Main.cpp)

# Create a static library for the day2 logic
add_library(day2_lib STATIC ${MODULE_SOURCES})

# Add the directory containing the header files for the main executable
target_include_directories(day2_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Create the main executable
get_filename_component(EXECUTABLE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_executable(${EXECUTABLE_NAME} ${MODULE_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/src/Day2Main.cpp)
target_link_libraries(day2 day2_lib)


# Create the test executable for day2
file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp)
add_executable(day2_tests ${TEST_SOURCES})

# Link googletest to the test executable
target_link_libraries(day2_tests gtest gtest_main day2_lib)

# Link the main source files to the test executable if needed
target_include_directories(day2_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${googletest_SOURCE_DIR}/googletest/include
)

# Register the test executable with CTest
add_test(NAME day2_tests COMMAND day2_tests)