#include "core.h"
#include <stdio.h>

namespace yes
{
    void Renderer::Init() const
    {
        if (!gladLoadGL())
        {
            Logger::Error(CORE_LOGGER, "[OpenGL] Failed to initialize glad");
            return;
        }

        // Print OpenGL version
        Logger::Info(CORE_LOGGER, "[OpenGL] Version: {}", (const char *)glGetString(GL_VERSION));
        Logger::Info(CORE_LOGGER, "[OpenGL] Shading Language Version: {}", (const char *)glGetString(GL_SHADING_LANGUAGE_VERSION));
        Logger::Info(CORE_LOGGER, "[OpenGL] Vendor: {}", (const char *)glGetString(GL_VENDOR));
        Logger::Info(CORE_LOGGER, "[OpenGL] Renderer: {}", (const char *)glGetString(GL_RENDERER));

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
            Logger::Error(CORE_LOGGER, "[OpenGL] {}", message);
            break;
        case GL_DEBUG_SEVERITY_MEDIUM:
            Logger::Warn(CORE_LOGGER, "[OpenGL] {}", message);
            break;
        case GL_DEBUG_SEVERITY_LOW:
            Logger::Info(CORE_LOGGER, "[OpenGL] {}", message);
            break;
        case GL_DEBUG_SEVERITY_NOTIFICATION:
            Logger::Trace(CORE_LOGGER, "[OpenGL] {}", message);
            break;
        }
    }
} // namespace yes
