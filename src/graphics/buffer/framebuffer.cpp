#include "core.h"

namespace yes
{
    Ref<FrameBuffer> FrameBuffer::Create()
    {
        Ref<FrameBuffer> result = CreateRef<FrameBuffer>();
        result->Init();
        return result;
    }

    void FrameBuffer::Init()
    {
        glGenFramebuffers(1, &id);
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
