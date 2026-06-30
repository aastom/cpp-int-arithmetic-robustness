cmake_minimum_required(VERSION 3.10)

project(int_arithmetic_robustness LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Specify source files
set(SOURCES
    src/main.cpp
    src/input_utils.cpp
)

# Include directories
include_directories(src)

# Add the executable
add_executable(int_checker ${SOURCES})

# Optional: Link against standard libraries if needed, though iostream/limits are typically implicitly linked
# target_link_libraries(int_checker)

# Optional: Add compiler flags for warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(int_checker PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
    )
endif()
