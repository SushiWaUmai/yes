#include "core.h"

namespace yes
{
    template <GLenum ShaderType>
    ShaderSource<ShaderType>::ShaderSource()
    {
        Init();
    }

    template <GLenum ShaderType>
    ShaderSource<ShaderType>::ShaderSource(const char *src)
    {
        Init(src);
    }

    template <GLenum ShaderType>
    ShaderSource<ShaderType>::~ShaderSource()
    {
        Delete();
    }

    template <GLenum ShaderType>
    Ref<ShaderSource<ShaderType>> ShaderSource<ShaderType>::Create()
    {
        return CreateRef<ShaderSource>();
    }

    template <GLenum ShaderType>
    void ShaderSource<ShaderType>::Init()
    {
        id = glCreateShader(ShaderType);
    }

    template <GLenum ShaderType>
    void ShaderSource<ShaderType>::Init(const char *src)
    {
        Init();
        Compile(src);
    }

    template <GLenum ShaderType>
    void ShaderSource<ShaderType>::Load(const char *path)
    {
        const char *src = load_file(path);
        Init(src);
        free((char *)src);
    }

    template <GLenum ShaderType>
    void ShaderSource<ShaderType>::Delete()
    {
        glDeleteShader(id);
    }

    template <GLenum ShaderType>
    bool ShaderSource<ShaderType>::Compile(const char *src)
    {
        glShaderSource(id, 1, &src, NULL);
        glCompileShader(id);

        GLint result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);

        if (!result)
        {
            GLint length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            char *message = new char[length];
            glGetShaderInfoLog(id, length, &length, message);
            Logger::Error(CORE_LOGGER, "[Shader] Failed to compile shader:\n{}", message);

            delete[] message;
            return false;
        }

        return true;
    }

} // namespace yes
