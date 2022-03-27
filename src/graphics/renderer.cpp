#include "core.h"

namespace yes
{
    void Renderer::Init()
    {
        gladLoadGL();
    }

    void Renderer::Submit(const Ref<VertexArray> &vertexArray)
    {
        vertexArray->EnableAllVertexAttributes();
        vertexArray->Bind();
        glDrawElements(GL_TRIANGLES, vertexArray->GetIndexCount(), vertexArray->GetIndexType(), nullptr);
    }
} // namespace yes
