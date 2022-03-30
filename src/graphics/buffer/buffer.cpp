#include "core.h"

namespace yes
{
    template <GLuint BufferType>
    Buffer<BufferType>::Buffer(GLsizei count, ShaderDataType type, const void *data, GLenum usage)
    {
        Init(count, type, data, usage);
    }

    template <GLuint BufferType>
    Buffer<BufferType>::~Buffer()
    {
        Delete();
    }

    template <GLuint BufferType>
    Ref<Buffer<BufferType>> Buffer<BufferType>::Create(GLsizei count, ShaderDataType type, const void *data, GLenum usage)
    {
        return CreateRef<Buffer<BufferType>>(count, type, data, usage);
    }

    template <GLuint BufferType>
    void Buffer<BufferType>::Init(GLsizei count, ShaderDataType type, const void *data, GLenum usage)
    {
        glGenBuffers(1, &id);
        this->count = count;
        this->dataType = type;

        Bind();
        glBufferData(BufferType, count * ShaderDataTypeUtils::ShaderDataTypeToSize(type), data, usage);
        Unbind();
    }

    template <GLuint BufferType>
    void Buffer<BufferType>::Delete() const
    {
        glDeleteBuffers(1, &id);
    }

    template <GLuint BufferType>
    void Buffer<BufferType>::Bind() const
    {
        glBindBuffer(BufferType, id);
    }

    template <GLuint BufferType>
    void Buffer<BufferType>::Unbind() const
    {
        glBindBuffer(BufferType, 0);
    }
}