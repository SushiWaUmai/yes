#include "core.h"
#include <iostream>

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
        Bind();
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(id);
    }

    void VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    void VertexArray::AddVertexBuffer(GLuint index, Ref<VertexBuffer> vertexBuffer)
    {
        vertexBuffers.insert({index, vertexBuffer});
    }

    void VertexArray::SetIndexBuffer(Ref<IndexBuffer> indexBuffer)
    {
        this->indexBuffer = indexBuffer;
    }

    void VertexArray::EnableVertexAttribute(GLuint index)
    {
        Bind();
        VertexBuffer *vb = vertexBuffers[index].get();
        vb->Bind();
        glVertexAttribPointer(index,
                            ShaderDataTypeUtils::ShaderDataTypeToComponentCount(vb->GetType()),
                            ShaderDataTypeUtils::ShaderDataTypeToGLType(vb->GetType()),
                            GL_FALSE,
                            ShaderDataTypeUtils::ShaderDataTypeToSize(vb->GetType()),
                            (void *)0);
        glEnableVertexAttribArray(index);
        vb->Unbind();
    }

    void VertexArray::EnableAllVertexAttributes()
    {
        Bind();
        // Index and Buffer
        for (auto &vertexBuffer : vertexBuffers)
        {
            vertexBuffer.second->Bind();
            EnableVertexAttribute(vertexBuffer.first);
        }
    }
}
