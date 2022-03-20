#include "core.h"

namespace yes
{
    FrameBuffer::FrameBuffer()
    {
        Init();
    }

    FrameBuffer::~FrameBuffer()
    {
        Delete();
    }

    Ref<FrameBuffer> FrameBuffer::Create()
    {
        return CreateRef<FrameBuffer>();
    }

    void FrameBuffer::Init()
    {
        glGenFramebuffers(1, &id);
    }

    void FrameBuffer::Delete() const
    {
        glDeleteFramebuffers(1, &id);
    }

    void FrameBuffer::Bind() const
    {
        glBindFramebuffer(GL_FRAMEBUFFER, id);
    }

    void FrameBuffer::Unbind() const
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
} // namespace yes
