#include "core.h"

namespace yes
{
    void Renderer::Init()
    {
        gladLoadGL();
    }

    void Renderer::Submit(const Ref<VertexArray> &vertexArray)
    {
        vertexArray->Bind();
        vertexArray->EnableAllVertexAttributes();
        glDrawElements(GL_TRIANGLES, vertexArray->GetIndexCount(), vertexArray->GetIndexType(), nullptr);
    }
} // namespace yes
