cmake_minimum_required(VERSION 3.0)

project(yes CXX)

add_subdirectory("./deps/glad/")
add_subdirectory("./deps/glfw/")

add_library(${PROJECT_NAME} STATIC
    "include/yes/yes.h"
    "src/core/application.h"
    "src/core/application.cpp"
    "src/core/window.h"
    "src/core/window.cpp"
    "src/core/graphics/buffer.h"
    "src/core/graphics/buffer.cpp"
    "src/core/graphics/shader.h"
    "src/core/graphics/shader.cpp"
    "src/utils/fileloader.h"
    "src/utils/fileloader.cpp"
)

target_compile_options(${PROJECT_NAME} INTERFACE "-lglad" PRIVATE "-lglfw3")
target_include_directories(${PROJECT_NAME} PRIVATE "./deps/glfw/include/" PRIVATE "./deps/glad/include" INTERFACE "./include/")
target_link_libraries(${PROJECT_NAME} PUBLIC "glad" "glfw")
