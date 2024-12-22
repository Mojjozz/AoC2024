# Automatically collect all .cpp files in the src folder
file(GLOB MODULE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# Create the executable
get_filename_component(EXECUTABLE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_executable(${EXECUTABLE_NAME} ${MODULE_SOURCES})