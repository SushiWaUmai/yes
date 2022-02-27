#pragma once
#include <glad/glad.h>

namespace yes
{
    class Buffer
    {
    public:
        virtual void Init(GLuint count, ShaderDataType type, const void *data, GLenum usage) = 0;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        inline GLuint GetID() const { return id; }
        inline GLuint GetCount() const { return count; }
        inline ShaderDataType GetType() const { return dataType; }

    protected:
        GLuint id;
        GLuint count;
        ShaderDataType dataType;
    };

}
