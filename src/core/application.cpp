#include "../core.h"

namespace yes
{
    void Application::Init()
    {
        window.Init("Hello World", 800, 600);
        renderer.Init();
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
