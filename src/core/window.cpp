#include "../core.h"

namespace yes
{
    void Window::Init(const char *title, int width, int height)
    {
        glfwInit();

        glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

        window = glfwCreateWindow(width, height, title, NULL, NULL);
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
