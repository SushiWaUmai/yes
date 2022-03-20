#pragma once

namespace yes
{
    class FrameBuffer
    {
    public:
        static Ref<FrameBuffer> Create();
        void Init();

        void Bind() const;
        void Unbind() const;

    private:
        GLuint id;
    };

} // namespace yes
