include(CheckCXXCompilerFlag)

if("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
    check_cxx_compiler_flag("/permissive-" CXX_SUPPORTS_PERMISSIVE_FLAG)
    if(CXX_SUPPORTS_PERMISSIVE_FLAG)
      add_compile_options($<$<COMPILE_LANGUAGE:CXX>:/permissive->)
    endif()
endif()
