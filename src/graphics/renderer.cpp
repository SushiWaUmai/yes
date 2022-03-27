#include "core.h"

namespace yes
{
    void Renderer::Init() const
    {
        gladLoadGL();
    }

    void Renderer::Submit(const Ref<VertexArray> &vertexArray) const
    {
        vertexArray->EnableAllVertexAttributes();
        vertexArray->Bind();
        glDrawElements(GL_TRIANGLES, vertexArray->GetIndexCount(), vertexArray->GetIndexType(), nullptr);
    }

    void Renderer::Clear() const
    {
        glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);
    }
} // namespace yes
