function(link_targets_by_pattern OUT_TARGET)
  set(multiValueArgs PATTERNS EXCLUDE)
  cmake_parse_arguments(PARSE "" "" "${multiValueArgs}" ${ARGN})

  if(NOT TARGET ${OUT_TARGET})
    add_library(${OUT_TARGET} INTERFACE)
  endif()

  # Collect all targets in the project
  set(ALL_DIRS ".")
  set(ALL_TARGETS "")
  set(INDEX 0)

  while(TRUE)
      list(LENGTH ALL_DIRS DIR_COUNT)
      if(NOT INDEX LESS DIR_COUNT)
          break()
      endif()

      list(GET ALL_DIRS ${INDEX} CURRENT_DIR)
      get_property(DIR_TARGETS DIRECTORY "${CURRENT_DIR}" PROPERTY BUILDSYSTEM_TARGETS)
      list(APPEND ALL_TARGETS ${DIR_TARGETS})

      get_property(SUB_DIRS DIRECTORY "${CURRENT_DIR}" PROPERTY SUBDIRECTORIES)
      list(APPEND ALL_DIRS ${SUB_DIRS})
      math(EXPR INDEX "${INDEX} + 1")
    endwhile()

    # Filter and Link the librarys
    foreach(TGT IN LISTS ALL_TARGETS)
      if("${TGT}" STREQUAL "${INTERFACE_LIB}")
          continue()
      endif()

      # Check Exclusions first
      set(IS_EXCLUDED FALSE)
      foreach(EX_PAT IN LISTS PARSE_EXCLUDE)
          if(TGT MATCHES "^${EX_PAT}.*")
              set(IS_EXCLUDED TRUE)
              break()
          endif()
      endforeach()

      if(IS_EXCLUDED)
          continue()
      endif()

      # Check Inclusion Patterns (Auto-wrapping with ^ and .*)
      foreach(PATTERN IN LISTS PARSE_PATTERNS)
          if(TGT MATCHES "^${PATTERN}.*")
              get_target_property(TGT_TYPE ${TGT} TYPE)
              # Ensure we only link libraries (Static, Shared, or Interface)
              if(NOT TGT_TYPE STREQUAL "EXECUTABLE")
                  message(STATUS "[${OUT_TARGET}] Auto-linked: ${TGT}")
                  target_link_libraries(${OUT_TARGET} INTERFACE ${TGT})
                  break() 
              endif()
          endif()
      endforeach()
    endforeach()
endfunction()
