#include "../../core.h"

namespace yes
{
    IndexBuffer::IndexBuffer(GLsizei count, ShaderDataType type, const void *data, GLenum usage)
    {
        Init(count, type, data, usage);
    }

    IndexBuffer::~IndexBuffer()
    {
        Delete();
    }

    Ref<IndexBuffer> IndexBuffer::Create(GLsizei count, ShaderDataType type, const void *data, GLenum usage)
    {
        return CreateRef<IndexBuffer>(count, type, data, usage);
    }

    void IndexBuffer::Init(GLsizei count, ShaderDataType type, const void *data, GLenum usage)
    {
        glGenBuffers(1, &id);
        this->count = count;
        this->dataType = type;

        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * ShaderDataTypeUtils::ShaderDataTypeToSize(type), data, usage);
    }

    void IndexBuffer::Delete() const
    {
        glDeleteBuffers(1, &id);
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
