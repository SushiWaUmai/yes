#pragma once

namespace yes
{
    class IndexBuffer : public Buffer
    {
    public:
        static Ref<IndexBuffer> Create(GLuint count, ShaderDataType type, const void *data, GLenum usage);

        void Init(GLuint count, ShaderDataType type, const void *data, GLenum usage) override;
        void Bind() const override;
        void Unbind() const override;
    };
}