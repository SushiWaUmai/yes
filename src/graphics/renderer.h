#pragma once

namespace yes
{
    class Renderer
    {
    public:
        void Init() const;
        void Submit(const Ref<VertexArray> &vertexArray) const;
        void Clear() const;
    };
} // namespace yes
