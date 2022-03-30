#include "../../core.h"

namespace yes
{
    template <typename T, GLuint BufferType>
    Buffer<T, BufferType>::Buffer(GLsizei count, ShaderDataType type, const void *data, GLenum usage)
    {
        Init(count, type, data, usage);
    }

    template <typename T, GLuint BufferType>
    Buffer<T, BufferType>::~Buffer()
    {
        Delete();
    }

    template <typename T, GLuint BufferType>
    Ref<T> Buffer<T, BufferType>::Create(GLsizei count, ShaderDataType type, const void *data, GLenum usage)
    {
        return CreateRef<T>(count, type, data, usage);
    }

    template <typename T, GLuint BufferType>
    void Buffer<T, BufferType>::Init(GLsizei count, ShaderDataType type, const void *data, GLenum usage)
    {
        glGenBuffers(1, &id);
        this->count = count;
        this->dataType = type;

        Bind();
        glBufferData(BufferType, count * ShaderDataTypeUtils::ShaderDataTypeToSize(type), data, usage);
        Unbind();
    }

    template <typename T, GLuint BufferType>
    void Buffer<T, BufferType>::Delete() const
    {
        glDeleteBuffers(1, &id);
    }

    template <typename T, GLuint BufferType>
    void Buffer<T, BufferType>::Bind() const
    {
        glBindBuffer(BufferType, id);
    }

    template <typename T, GLuint BufferType>
    void Buffer<T, BufferType>::Unbind() const
    {
        glBindBuffer(BufferType, 0);
    }
}