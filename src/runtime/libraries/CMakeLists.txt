# Get all C++ files for System.Private.CoreLib
file(GLOB_RECURSE SYSTEM_PRIVATE_CORELIB_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/System.Private.CoreLib/*.cpp"
)

add_library(System.Private.CoreLib ${SYSTEM_PRIVATE_CORELIB_SOURCES})
set_target_properties(System.Private.CoreLib PROPERTIES PREFIX "")
