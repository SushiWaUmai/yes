#pragma once

namespace yes
{
    class IndexBuffer
    {
    public:
        IndexBuffer() = default;
        IndexBuffer(GLsizei count, ShaderDataType type, const void *data, GLenum usage);
        ~IndexBuffer();

        static Ref<IndexBuffer> Create(GLsizei count, ShaderDataType type, const void *data, GLenum usage);

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
}
