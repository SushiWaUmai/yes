#include <glad/glad.h>
#include "indexbuffer.h"

namespace yes
{
    void IndexBuffer::Init(GLsizeiptr size, const void *data, GLenum usage)
    {
        glGenBuffers(1, &id);

        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);
        Unbind();
    }

    void IndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    }

    void IndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}
