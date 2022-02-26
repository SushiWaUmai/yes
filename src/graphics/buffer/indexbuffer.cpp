#include "../../core.h"

namespace yes
{
    Ref<IndexBuffer> IndexBuffer::Create(GLsizeiptr size, const void *data, GLenum usage)
    {
        Ref<IndexBuffer> result = CreateRef<IndexBuffer>();
        result->Init(size, data, usage);
        return result;
    }

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
