project(tests)

macro(add_test name)
  add_executable(${name} ${name}.cpp)
  target_link_libraries(${name} dotnetcpp)
endmacro()

add_test(StringTest)
