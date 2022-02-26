#pragma once
#include <vector>

namespace yes {
    class VertexArray {
    public:
        static Ref<VertexArray> Create();

        void Init();
        void Bind() const;
        void Unbind() const;

        void AddVertexBuffer(Ref<VertexBuffer> vertexBuffer);
        void SetIndexBuffer(Ref<IndexBuffer> indexBuffer);
    private:
        GLuint id;
        std::vector<Ref<VertexBuffer>> vertexBuffers;
        Ref<IndexBuffer> indexBuffer;
    };
}