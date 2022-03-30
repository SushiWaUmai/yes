cmake_minimum_required(VERSION 3.0)

project(yes CXX)

add_subdirectory("./deps/glad/")
add_subdirectory("./deps/glfw/")
add_subdirectory("./deps/glm/")

add_library(${PROJECT_NAME} STATIC
    "include/yes/yes.h"
    "src/core.h"
    "src/core/ref.h"
    "src/core/application.h"
    "src/core/application.cpp"
    "src/core/window.h"
    "src/core/window.cpp"
    "src/graphics/buffer/buffer.h"
    "src/graphics/buffer/buffer.cpp"
    "src/graphics/buffer/buffertypes.h"
    "src/graphics/buffer/framebuffer.h"
    "src/graphics/buffer/framebuffer.cpp"
    "src/graphics/buffer/vertexarray.h"
    "src/graphics/buffer/vertexarray.cpp"
    "src/graphics/shader/shaderdata.h"
    "src/graphics/shader/shaderdata.cpp"
    "src/graphics/shader/shader.h"
    "src/graphics/shader/shader.cpp"
    "src/graphics/shader/shadersource.h"
    "src/graphics/shader/shadersource.cpp"
    "src/graphics/renderer.h"
    "src/graphics/renderer.cpp"
    "src/graphics/texture.h"
    "src/graphics/texture.cpp"
    "src/utils/fileloader.h"
    "src/utils/fileloader.cpp"
)

target_compile_options(${PROJECT_NAME} INTERFACE "-lglad" PRIVATE "-lglfw3")
target_include_directories(${PROJECT_NAME}
    PRIVATE "./deps/glfw/include/"
    PRIVATE "./deps/glad/include/"
    PRIVATE "./deps/stb/"
    PRIVATE "./src/"
    PUBLIC  "./include/"
)

target_link_libraries(${PROJECT_NAME} PUBLIC "glad" "glfw" "glm")
