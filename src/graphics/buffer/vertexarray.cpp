#include "vertexarray.h"

namespace yes
{
    void VertexArray::Init()
    {
        glGenVertexArrays(1, &id);
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(id);
    }

    void VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }
}