project(Tests)

add_executable(BasicTest BasicTest.cpp)
target_link_libraries(BasicTest PRIVATE dotnetcpp)

add_test(NAME BasicTest COMMAND BasicTest)
