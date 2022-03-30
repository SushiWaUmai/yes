#pragma once
#include "../../core.h"

namespace yes
{
    template<typename T, GLuint BufferType>
    class Buffer
    {
    public:
        Buffer() = default;
        Buffer(GLsizei count, ShaderDataType type, const void *data, GLenum usage);
        ~Buffer();

        static Ref<T> Create(GLsizei count, ShaderDataType type, const void *data, GLenum usage);

        void Init(GLsizei count, ShaderDataType type, const void *data, GLenum usage);
        void Delete() const;

        void Bind() const;
        void Unbind() const;

        inline GLuint GetID() const { return id; }
        inline GLuint GetCount() const { return count; }
        inline ShaderDataType GetType() const { return dataType; }

    private:
        GLuint id;
        GLsizei count;
        ShaderDataType dataType;
    };
} // namespace yes
