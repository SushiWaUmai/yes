cmake_minimum_required(VERSION 3.0)

project(yes CXX)

add_subdirectory("./deps/glad")

add_subdirectory("./deps/glfw")
include_directories("./deps/glfw/include")

add_compile_options("-lglad" "-lglfw3")

add_executable(yes "src/main.cpp")
target_link_libraries(yes "glad" "glfw")
