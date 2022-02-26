#pragma once

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
}
