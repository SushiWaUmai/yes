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

    void FrameBuffer::AttachTexture(Ref<Texture> texture)
    {
        Bind();
        texture->Bind();
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture->GetID(), 0);
        texture->Unbind();
        Unbind();
    }

    void FrameBuffer::Bind() const
    {
        // check that the framebuffer is complete
        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        {
            Logger::Error(CORE_LOGGER, "[OpenGL] Framebuffer is not complete");
            return;
        }

        glBindFramebuffer(GL_FRAMEBUFFER, id);
    }

    void FrameBuffer::Unbind() const
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
} // namespace yes
