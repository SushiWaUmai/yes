#pragma once
#include <GLFW/glfw3.h>
#include "graphics/texture.h"
#include "core/ref.h"

namespace yes
{
    class FrameBuffer
    {
    public:
        FrameBuffer();
        ~FrameBuffer();

        static Ref<FrameBuffer> Create();

        void Init();
        void Delete() const;

        void AttachTexture(Ref<Texture> texture);

        void Bind() const;
        void Unbind() const;

    private:
        GLuint id;
    };

} // namespace yes
