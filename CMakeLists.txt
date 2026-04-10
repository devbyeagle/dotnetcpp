cmake_minimum_required(VERSION 3.19)
project(dotnetcpp LANGUAGES CXX VERSION "1.0.0")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Use C++17.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
#set(CMAKE_CXX_EXTENSIONS NO)

# Include common CMake utilities first.
include(Utils)
include(GNUInstallDirs)

option(DOTNETCPP_INCLUDE_TESTS "Include test targets in the build." TRUE)

if(CMAKE_CXX_COMPILER_ID MATCHES Clang)
  add_compile_options($<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-Werror=gnu>)
endif()

include_directories(BEFORE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  )

# Include only necessary subdirectories.
add_subdirectory(src/runtime)

if(DOTNETCPP_INCLUDE_TESTS)
  add_subdirectory(src/runtime/tests)
endif()

link_targets_by_pattern(dotnetcpp
    PATTERNS
        System
)
