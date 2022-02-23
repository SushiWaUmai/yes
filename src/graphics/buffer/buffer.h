#pragma once
#include <glad/glad.h>

namespace yes
{
    class Buffer
    {
    public:
        virtual void Init(GLsizeiptr size, const void *data, GLenum usage) = 0;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        inline GLuint GetID() const { return id; }

    protected:
        GLuint id;
    };

}
