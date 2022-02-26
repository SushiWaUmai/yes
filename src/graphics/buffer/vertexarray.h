#pragma once

namespace yes {
    class VertexArray {
    public:
        static Ref<VertexArray> Create();

        void Init();
        void Bind() const;
        void Unbind() const;
    private:
        GLuint id;
    };
}