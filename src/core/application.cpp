#include "core.h"

namespace yes
{
    void Application::Init()
    {
        Init("Yes", 1280, 720);
    }

    void Application::Init(const char *title, int width, int height)
    {
        Logger::Create(CORE_LOGGER);
        Logger::SetLevel(CORE_LOGGER, spdlog::level::trace);
        
        window.Init(title, width, height);
        renderer.Init();

        Start();
    }

    void Application::Start()
    {
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

    Application::~Application()
    {
        glfwTerminate();
    }
}
