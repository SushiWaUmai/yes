#pragma once

#include "buffer.h"

namespace yes
{
    class IndexBuffer : public Buffer {
    public:
        void Init(GLsizeiptr size, const void *data, GLenum usage);
        void Bind() const;
        void Unbind() const;
    };
}