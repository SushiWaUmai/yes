#include "../../core.h"

namespace yes
{
    VertexBuffer::VertexBuffer(GLsizei count, ShaderDataType type, const void *data, GLenum usage)
    {
        Init(count, type, data, usage);
    }

    VertexBuffer::~VertexBuffer()
    {
        Delete();
    }

    Ref<VertexBuffer> VertexBuffer::Create(GLsizei count, ShaderDataType type, const void *data, GLenum usage)
    {
        return CreateRef<VertexBuffer>(count, type, data, usage);
    }

    void VertexBuffer::Init(GLsizei count, ShaderDataType type, const void *data, GLenum usage)
    {
        glGenBuffers(1, &id);
        this->count = count;
        this->dataType = type;

        Bind();
        glBufferData(GL_ARRAY_BUFFER, count * ShaderDataTypeUtils::ShaderDataTypeToSize(type), data, usage);
        Unbind();
    }

    void VertexBuffer::Delete() const
    {
        glDeleteBuffers(1, &id);
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
