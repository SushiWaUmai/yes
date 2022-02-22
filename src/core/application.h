#pragma once
#include "window.h"

namespace yes
{
    class Application
    {
    public:
        virtual void Init();
        void Run();
        virtual void Update();
        virtual void Terminate();

    private:
        Window window;
    };
} // namespace yes
