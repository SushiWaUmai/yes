#include "core.h"

namespace yes
{
    VertexArray::VertexArray()
    {
        Init();
    }

    VertexArray::~VertexArray()
    {
        Delete();
    }

    Ref<VertexArray> VertexArray::Create()
    {
        return CreateRef<VertexArray>();
    }
    
    void VertexArray::Init()
    {
        glGenVertexArrays(1, &id);
    }

    void VertexArray::Delete() const
    {
        glDeleteVertexArrays(1, &id);
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(id);
        indexBuffer->Bind();
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
                            ShaderDataTypeUtils::ToComponentCount(vb->GetType()),
                            ShaderDataTypeUtils::ToGLType(vb->GetType()),
                            GL_FALSE,
                            ShaderDataTypeUtils::ToSize(vb->GetType()),
                            (void *)0);
        glEnableVertexAttribArray(index);
        vb->Unbind();
        Unbind();
    }

    void VertexArray::EnableAllVertexAttributes()
    {
        Bind();
        indexBuffer->Bind();
        // Index and Buffer
        for (auto &vertexBuffer : vertexBuffers)
            EnableVertexAttribute(vertexBuffer.first);
        Unbind();
    }
}
