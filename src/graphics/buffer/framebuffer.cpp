#include "core.h"
#include <cassert>

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
        // assert that the framebuffer is complete
        assert(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE);
        glBindFramebuffer(GL_FRAMEBUFFER, id);
    }

    void FrameBuffer::Unbind() const
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
} // namespace yes
