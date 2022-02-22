#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glad/glad.h>
#include "application.h"

namespace yes
{
    void Application::Init()
    {
        glfwInit();
        window.Init("Hello World", 800, 600);

        gladLoadGL();
    }

    void Application::Run()
    {
        while (!window.shouldClose())
        {
            window.Run();
        }
    }

    void Application::Terminate()
    {
        glfwTerminate();
    }
} // namespace yes
