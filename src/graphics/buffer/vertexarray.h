#pragma once
#include <unordered_map>

namespace yes
{
    class VertexArray
    {
    public:
        static Ref<VertexArray> Create();

        void Init();
        void Bind() const;
        void Unbind() const;

        void AddVertexBuffer(GLuint index, Ref<VertexBuffer> vertexBuffer);
        void SetIndexBuffer(Ref<IndexBuffer> indexBuffer);

        void EnableVertexAttribute(GLuint index);
        void EnableAllVertexAttributes();

        inline GLsizei GetIndexCount() const
        {
            return indexBuffer->GetCount() *
                   ShaderDataTypeUtils::ShaderDataTypeToComponentCount(indexBuffer->GetType());
        }
        
        inline GLenum GetIndexType() const
        {
            return ShaderDataTypeUtils::ShaderDataTypeToGLType(indexBuffer->GetType());
        }

        inline GLuint GetID() const { return id; }
        inline GLsizei GetVertexBufferCount() const { return vertexBuffers.size(); }

    private:
        GLuint id;
        std::unordered_map<GLuint, Ref<VertexBuffer>> vertexBuffers;
        Ref<IndexBuffer> indexBuffer;
    };
}
