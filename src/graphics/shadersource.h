#pragma once

namespace yes
{
    class ShaderSource
    {
    public:
        ShaderSource(GLenum type);
        ShaderSource(const char *src, GLenum type);
        ~ShaderSource();

        static Ref<ShaderSource> Create(GLenum type);

        void Init(GLenum type);
        void Init(const char *src, GLenum type);
        void Load(const char *path, GLenum type);
        void Delete();

        inline GLuint GetID() const { return id; }

    private:
        bool Compile(const char *src);

        GLuint id;
    };
} // namespace yes
