#pragma once
#include <glad/glad.h>

namespace yes
{
    class Buffer
    {
    public:
        void Init(GLenum target, GLsizeiptr size, const void *data, GLenum usage);

        void Bind() const;
        void Unbind() const;

        inline GLuint GetID() const { return id; }

    private:
        GLuint id;
        GLuint target;
    };

}
