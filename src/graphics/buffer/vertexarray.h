#pragma once
#include <vector>
#include <unordered_map>

namespace yes {
    class VertexArray {
    public:
        static Ref<VertexArray> Create();

        void Init();
        void Bind() const;
        void Unbind() const;

        void AddVertexBuffer(GLuint index, Ref<VertexBuffer> vertexBuffer);
        void SetIndexBuffer(Ref<IndexBuffer> indexBuffer);
        
        void EnableVertexAttribute(GLuint index);
        void EnableAllVertexAttributes();
    private:
        GLuint id;
        std::unordered_map<GLuint, Ref<VertexBuffer>> vertexBuffers;
        Ref<IndexBuffer> indexBuffer;
    };
}