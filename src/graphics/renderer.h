#pragma once
#include <GLFW/glfw3.h>
#include "graphics/buffer/vertexarray.h"

namespace yes
{
    class Renderer
    {
    public:
        void Init() const;
        void Submit(const Ref<VertexArray> &vertexArray) const;
        void Clear() const;

    private:
        static void debug_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
    };
} // namespace yes
