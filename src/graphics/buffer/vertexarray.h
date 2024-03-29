#pragma once
#include <GLFW/glfw3.h>
#include <unordered_map>
#include "core/ref.h"
#include "graphics/buffer/buffertypes.h"

namespace yes
{
    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        static Ref<VertexArray> Create();

        void Init();
        void Delete() const;

        void Bind() const;
        void Unbind() const;

        void AddVertexBuffer(GLuint index, Ref<VertexBuffer> vertexBuffer);
        void SetIndexBuffer(Ref<IndexBuffer> indexBuffer);

        void EnableVertexAttribute(GLuint index);
        void EnableAllVertexAttributes();

        inline GLsizei GetIndexCount() const
        {
            return indexBuffer->GetCount() *
                   ShaderDataTypeUtils::ToComponentCount(indexBuffer->GetType());
        }
        
        inline GLenum GetIndexType() const
        {
            return ShaderDataTypeUtils::ToGLType(indexBuffer->GetType());
        }

        inline GLuint GetID() const { return id; }
        inline GLsizei GetVertexBufferCount() const { return vertexBuffers.size(); }

    private:
        GLuint id;
        std::unordered_map<GLuint, Ref<VertexBuffer>> vertexBuffers;
        Ref<IndexBuffer> indexBuffer;
    };
}
