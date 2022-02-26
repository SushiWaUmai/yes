#pragma once

namespace yes
{
    class VertexBuffer : public Buffer
    {
    public:
        static Ref<VertexBuffer> Create(GLsizeiptr size, const void *data, GLenum usage);
        void Init(GLsizeiptr size, const void *data, GLenum usage);
        void Bind() const;
        void Unbind() const;
    };
}