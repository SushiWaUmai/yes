#include "../../core.h"

namespace yes
{
    Ref<VertexBuffer> VertexBuffer::Create(GLsizei count, ShaderDataType type, const void *data, GLenum usage)
    {
        Ref<VertexBuffer> result = CreateRef<VertexBuffer>();
        result->Init(count, type, data, usage);
        return result;
    }

    void VertexBuffer::Init(GLsizei count, ShaderDataType type, const void *data, GLenum usage)
    {
        glGenBuffers(1, &id);
        this->count = count;
        this->dataType = type;

        Bind();
        glBufferData(GL_ARRAY_BUFFER, count * ShaderDataTypeUtils::ShaderDataTypeToSize(type), data, usage);
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