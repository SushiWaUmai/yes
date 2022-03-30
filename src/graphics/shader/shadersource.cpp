#include "core.h"
#include <iostream>
#include <cassert>
#include <stdlib.h>

namespace yes
{
    ShaderSource::ShaderSource(GLenum type)
    {
        Init(type);
    }

    ShaderSource::ShaderSource(const char *src, GLenum type)
    {
        Init(src, type);
    }

    ShaderSource::~ShaderSource()
    {
        Delete();
    }

    Ref<ShaderSource> ShaderSource::Create(GLenum type)
    {
        return CreateRef<ShaderSource>(type);
    }

    void ShaderSource::Init(GLenum type)
    {
        id = glCreateShader(type);
    }

    void ShaderSource::Init(const char *src, GLenum type)
    {
        Init(type);
        Compile(src);
    }

    void ShaderSource::Load(const char *path, GLenum type)
    {
        const char *source = load_file(path);
        Init(source, type);
        free((char *)source);
    }

    void ShaderSource::Delete()
    {
        glDeleteShader(id);
    }

    bool ShaderSource::Compile(const char *src)
    {
        glShaderSource(id, 1, &src, NULL);
        glCompileShader(id);

        GLint result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);

        // For now
        assert(result);
        if (!result)
        {
            GLint length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            char *message = (char *)malloc(length * sizeof(char));
            glGetShaderInfoLog(id, length, &length, message);

            std::cout << "Failed to compile vertex shader" << std::endl
                      << message << std::endl;
            free(message);
            return false;
        }

        return true;
    }

} // namespace yes
