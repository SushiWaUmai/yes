#include "buffer.h"

namespace yes
{
    void Buffer::Init(GLenum target, GLsizeiptr size, const void *data, GLenum usage)
    {
        glGenBuffers(1, &id);
        this->target = target;

        Bind();
        glBufferData(target, size, data, usage);
        Unbind();
    }

    void Buffer::Bind() const
    {
        glBindBuffer(target, id);
    }

    void Buffer::Unbind() const
    {
        glBindBuffer(target, 0);
    }

}
