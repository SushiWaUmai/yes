#include "window.h"

namespace yes
{
    void Window::Init(const char *title, int width, int height)
    {
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
