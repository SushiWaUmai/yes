#pragma once

namespace yes
{
    class VertexBuffer : public Buffer
    {
    public:
        static Ref<VertexBuffer> Create(GLsizei count, ShaderDataType type, const void *data, GLenum usage);
        
        void Init(GLsizei count, ShaderDataType type, const void *data, GLenum usage) override;
        void Bind() const override;
        void Unbind() const override;
    };
}