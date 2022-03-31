#include "core.h"
#include <cassert>
#include <stdio.h>

namespace yes
{
    void Renderer::Init() const
    {
        assert(gladLoadGL());

        // Print OpenGL version
        fprintf(stdout, "[INFO] OpenGL version: %s\n", glGetString(GL_VERSION));

        glDebugMessageCallback(debug_callback, nullptr);
    }

    void Renderer::Submit(const Ref<VertexArray> &vertexArray) const
    {
        vertexArray->EnableAllVertexAttributes();
        vertexArray->Bind();
        glDrawElements(GL_TRIANGLES, vertexArray->GetIndexCount(), vertexArray->GetIndexType(), nullptr);
    }

    void Renderer::Clear() const
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::debug_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
    {
        switch (severity)
        {
        case GL_DEBUG_SEVERITY_HIGH:
            fprintf(stderr, "[ERROR] %s\n", message);
            break;
        case GL_DEBUG_SEVERITY_MEDIUM:
            fprintf(stderr, "[WARN] %s\n", message);
            break;
        case GL_DEBUG_SEVERITY_LOW:
            fprintf(stderr, "[INFO] %s\n", message);
            break;
        case GL_DEBUG_SEVERITY_NOTIFICATION:
            fprintf(stdout, "[TRACE] %s\n", message);
            break;
        }
    }
} // namespace yes
