#include "../../core.h"

namespace yes
{
    Ref<VertexArray> VertexArray::Create()
    {
        Ref<VertexArray> result = CreateRef<VertexArray>();
        result->Init();
        return result;
    }

    void VertexArray::Init()
    {
        glGenVertexArrays(1, &id);
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(id);
    }

    void VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }
    
    void VertexArray::AddVertexBuffer(Ref<VertexBuffer> vertexBuffer)
    {
        vertexBuffers.push_back(vertexBuffer);
    }

    void VertexArray::SetIndexBuffer(Ref<IndexBuffer> indexBuffer)
    {
        this->indexBuffer = indexBuffer;
    }
}