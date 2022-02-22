#include "buffer.h"

namespace yes
{
    void Buffer::Init(GLenum target, GLsizeiptr size, const void *data, GLenum usage)
    {
        glGenBuffers(1, &id);

        Bind();
        glBufferData(target, size, data, usage);
        Unbind();
    }

    void Buffer::Bind()
    {
        glBindBuffer(target, id);
    }

    void Buffer::Unbind()
    {
        glBindBuffer(target, 0);
    }

} // namespace yes
