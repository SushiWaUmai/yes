#include "core.h"

namespace yes {
void Application::Init() {
    Init("Yes", 1280, 720);
}

void Application::Init(const char *title, int width, int height) {
    Logger::Create(CORE_LOGGER);
    Logger::SetLevel(CORE_LOGGER, Logger::Level::trace);

    Start(title, width, height);
}

void Application::Start(const char *title, int width, int height) {
    window.Init(title, width, height);
    renderer.Init();
}

void Application::Run() {
    while (!window.shouldClose()) {
        Update();
    }
}

void Application::Update() {
    window.Update();
}

Application::~Application() {
    glfwTerminate();
}
} // namespace yes
