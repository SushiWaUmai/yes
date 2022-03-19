#pragma once

namespace yes
{
    class IndexBuffer : public Buffer
    {
    public:
        static Ref<IndexBuffer> Create(GLsizei count, ShaderDataType type, const void *data, GLenum usage);

        void Init(GLsizei count, ShaderDataType type, const void *data, GLenum usage) override;
        void Bind() const override;
        void Unbind() const override;
    };
}