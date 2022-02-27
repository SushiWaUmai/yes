#include "../../core.h"

namespace yes
{
    Ref<IndexBuffer> IndexBuffer::Create(GLuint count, ShaderDataType type, const void *data, GLenum usage)
    {
        Ref<IndexBuffer> result = CreateRef<IndexBuffer>();
        result->Init(count, type, data, usage);
        return result;
    }

    void IndexBuffer::Init(GLuint count, ShaderDataType type, const void *data, GLenum usage)
    {
        glGenBuffers(1, &id);
        this->count = count;
        this->dataType = type;

        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * ShaderDataTypeUtils::ShaderDataTypeToSize(type), data, usage);
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
