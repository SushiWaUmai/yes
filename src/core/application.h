#pragma once

namespace yes {
class Application {
public:
    void Init();
    virtual void Init(const char *title, int width, int height);
    void Run();

protected:
    ~Application();

    virtual void Start(const char *title, int width, int height);
    virtual void Update();

    Window window;
    Renderer renderer;
};
} // namespace yes
