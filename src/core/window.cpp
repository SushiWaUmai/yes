#include "core.h"
#include <cassert>
#include <stdio.h>

namespace yes
{
    Window *Window::current = nullptr;

    void Window::Init(const char *title, int width, int height)
    {
        assert(glfwInit());

        glfwSetErrorCallback(error_callback);

        glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

        // OpenGL
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

        window = glfwCreateWindow(width, height, title, NULL, NULL);
        assert(window);
        MakeCurrent();
    }

    void Window::Run()
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    void Window::Destroy()
    {
        glfwDestroyWindow(window);
    }

    void Window::MakeCurrent()
    {
        glfwMakeContextCurrent(window);
        current = this;
    }

    void Window::error_callback(int error, const char *description)
    {
        Logger::Error(CORE_LOGGER, "[GLFW] %s", description);
    }
}
