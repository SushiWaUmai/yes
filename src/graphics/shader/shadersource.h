#pragma once
#include <GLFW/glfw3.h>
#include "core/ref.h"

namespace yes
{
    template <GLenum ShaderType>
    class ShaderSource
    {
    public:
        ShaderSource();
        ShaderSource(const char *src);
        ~ShaderSource();

        static Ref<ShaderSource> Create();

        void Init();
        void Init(const char *src);
        void Load(const char *path);
        void Delete();

        inline GLuint GetID() const { return id; }

        explicit operator GLuint() const { return id; }
    private:
        bool Compile(const char *src);

        GLuint id;
    };
} // namespace yes
