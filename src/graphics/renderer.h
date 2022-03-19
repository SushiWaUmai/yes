#pragma once

namespace yes
{
    class Renderer
    {
    public:
        void Init();
        void Submit(const Ref<VertexArray> &vertexArray);
    };
} // namespace yes
