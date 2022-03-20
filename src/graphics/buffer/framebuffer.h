#pragma once

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

        void Bind() const;
        void Unbind() const;

    private:
        GLuint id;
    };

} // namespace yes
