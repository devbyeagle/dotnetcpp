cmake_minimum_required(VERSION 3.19)
project(dotnetcpp VERSION 1.0.0 LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# Include common CMake utilities first.
include(functions)
include(GNUInstallDirs)

#
# Configurable options
#

option(BUILD_SHARED_LIBS
  "Build shared libraries"
  TRUE)

option(DOTNETCPP_INCLUDE_TESTS "Create targets for building and running tests." TRUE)

if(CMAKE_C_COMPILER_ID MATCHES Clang)
  add_compile_options($<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-Werror=gnu>)
endif()

include_directories(BEFORE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  )

# Include only necessary subdirectories.
add_subdirectory(src/runtime/src/libraries)

if(DOTNETCPP_INCLUDE_TESTS)
  add_subdirectory(src/runtime/src/tests)
endif()

link_targets_by_pattern(dotnetcpp
    PATTERNS
        System
)
