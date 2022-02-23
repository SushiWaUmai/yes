#include <glad/glad.h>

#include "vertexbuffer.h"

namespace yes {
    
    void VertexBuffer::Init(GLsizeiptr size, const void *data, GLenum usage)
    {
        glGenBuffers(1, &id);

        Bind();
        glBufferData(GL_ARRAY_BUFFER, size, data, usage);
        Unbind();
    }

    void VertexBuffer::Bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, id);
    }

    void VertexBuffer::Unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}