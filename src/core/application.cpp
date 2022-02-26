#include "../core.h"

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
            Update();
        }
    }

    void Application::Update()
    {
        window.Run();
    }

    void Application::Terminate()
    {
        glfwTerminate();
    }
}
