cmake_minimum_required(VERSION 3.19)
project(dotnetcpp LANGUAGES CXX VERSION "1.0.0")

# if(POLICY CMP0130)
#     cmake_policy(SET CMP0130 NEW)
# endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Use C++17.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# Include common CMake utilities first.
include(macros)
include(GNUInstallDirs)

option(DOTNETCPP_INCLUDE_TESTS "Include test targets in the build." TRUE)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
endif()

include(CompilerFlags)

include_directories(BEFORE
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

# Include only necessary subdirectories.
add_subdirectory(src/runtime)

if(DOTNETCPP_INCLUDE_TESTS)
  add_subdirectory(src/runtime/tests)
endif()

link_project_libraries(dotnetcpp
    PATTERNS
        System
)
