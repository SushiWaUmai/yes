#pragma once

namespace yes
{
    class Application
    {
    public:
        void Init();
        void Init(const char *title, int width, int height);
        void Run();

    protected:
        ~Application();

        void CreateWindow(const char *title, int width, int height);

        virtual void Start();
        virtual void Update();

        Window window;
        Renderer renderer;
    };
}
