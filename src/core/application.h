#pragma once
#include "window.h"

namespace yes
{
    class Application
    {
    public:
        void Init();
        void Run();
        void Terminate();

    private:
        Window window;
    };
} // namespace yes
