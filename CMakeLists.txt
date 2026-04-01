cmake_minimum_required(VERSION 3.19)
project(dotnetcpp LANGUAGES CXX VERSION "1.0.0")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Add path for custom CMake modules.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_DISABLE_IN_SOURCE_BUILD YES)

# Use C++17.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# Include common CMake utilities first.
include(functions)
include(GNUInstallDirs)

#
# Configuration options.
#

option(BUILD_SHARED_LIBS
  "Build shared libraries"
  TRUE)

option(DOTNETCPP_INCLUDE_TESTS "Include test targets in the build." TRUE)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
endif()

#
# End of Configuration options.
#

if(CMAKE_C_COMPILER_ID MATCHES Clang)
  add_compile_options($<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-Werror=gnu>)
endif()

include_directories(BEFORE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  )

# Include only necessary subdirectories.
add_subdirectory(src/runtime/libraries)

if(DOTNETCPP_INCLUDE_TESTS)
  add_subdirectory(src/runtime/tests)
endif()

# Finds all libraries in the project matching the names specified in PATTERNS
# and excludes any libraries listed in EXCLUDE.
link_targets_by_pattern(dotnetcpp
    PATTERNS
        System
)
