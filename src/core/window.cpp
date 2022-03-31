#include "core.h"
#include <cassert>

namespace yes
{
    void Window::Init(const char *title, int width, int height)
    {
        assert(glfwInit());

        glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, title, NULL, NULL);
        assert(window);
        glfwMakeContextCurrent(window);
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
}
