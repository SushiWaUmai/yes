#pragma once

namespace yes
{
    class Window
    {
    public:
        void Init(const char *title, int width, int height);
        void Run();
        void Destroy();

        void MakeCurrent();

        inline bool shouldClose() const { return glfwWindowShouldClose(window); }

    private:
        GLFWwindow *window;

        static Window *current;

        static void error_callback(int error, const char *description);
    };
}
