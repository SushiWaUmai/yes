#pragma once
#include "../../core/base.h"
#include <glad/glad.h>
#include "buffer.h"
#include <vector>

namespace yes {
    class VertexArray {
    public:
        VertexArray() = default;
        ~VertexArray() = default;

        void Init();
        void Bind() const;
        void Unbind() const;
    private:
        GLuint id;
    };
}