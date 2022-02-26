#include "../../core.h"

namespace yes
{
    Ref<VertexBuffer> VertexBuffer::Create(GLsizeiptr size, const void *data, GLenum usage)
    {
        Ref<VertexBuffer> result = CreateRef<VertexBuffer>();
        result->Init(size, data, usage);
        return result;
    }

    void VertexBuffer::Init(GLsizeiptr size, const void *data, GLenum usage)
    {
        glGenBuffers(1, &id);

        Bind();
        glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    }

    void VertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, id);
    }

    void VertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}