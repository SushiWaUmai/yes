#pragma once

namespace yes
{
    class IndexBuffer : public Buffer
    {
    public:
        static Ref<IndexBuffer> Create(GLsizeiptr size, const void *data, GLenum usage);
        void Init(GLsizeiptr size, const void *data, GLenum usage);
        void Bind() const;
        void Unbind() const;
    };
}