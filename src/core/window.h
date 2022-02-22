#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "graphics/buffer.h"

namespace yes
{
    class Window
    {
    public:
        void Init(const char *title, int width, int height);
        void Run();
        void Destroy();

        inline bool shouldClose() const { return glfwWindowShouldClose(window); }

    private:
        GLFWwindow *window;
    };
} // namespace yes