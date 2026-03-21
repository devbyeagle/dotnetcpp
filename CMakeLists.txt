cmake_minimum_required(VERSION 3.19)

project(dotnetcpp VERSION 1.0.0 LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# Include common CMake utilities first.
include(CMakeDependentOption)
include(GNUInstallDirs)
include(functions)

#
# User-configurable options.
#

option(BUILD_SHARED_LIBS
  "Build shared libraries"
  TRUE)

option(DOTNETCPP_INCLUDE_TESTS "Create targets for building/running tests." TRUE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(BEFORE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  )

# Include only necessary subdirectories.
add_subdirectory(src/runtime/src/libraries)

if(DOTNETCPP_INCLUDE_TESTS)
  add_subdirectory(tests)
endif()

link_targets_by_pattern(dotnetcpp
    PATTERNS
        System
)
