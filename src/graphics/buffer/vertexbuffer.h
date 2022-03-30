#pragma once
namespace yes
{
    class VertexBuffer : public Buffer<VertexBuffer, GL_ARRAY_BUFFER>
    {
    // public:
    //     VertexBuffer() = default;
    //     VertexBuffer(GLsizei count, ShaderDataType type, const void *data, GLenum usage);
    //     ~VertexBuffer();

    //     static Ref<VertexBuffer> Create(GLsizei count, ShaderDataType type, const void *data, GLenum usage);
        
    //     void Init(GLsizei count, ShaderDataType type, const void *data, GLenum usage);
    //     void Delete() const;

    //     void Bind() const;
    //     void Unbind() const;

    //     inline GLuint GetID() const { return id; }
    //     inline GLuint GetCount() const { return count; }
    //     inline ShaderDataType GetType() const { return dataType; }

    // private:
    //     GLuint id;
    //     GLsizei count;
    //     ShaderDataType dataType;
    };
}
