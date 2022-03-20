#pragma once

namespace yes
{
    class Texture
    {
    public:
        Texture() = default;
        Texture(const char *path);
        ~Texture();

        static Ref<Texture> Create(const char *path);

        void Init(const char *path);
        void Delete() const;

        void Bind() const;
        void Unbind() const;

        inline GLuint GetID() const { return id; }
    private:
        GLuint id;
        int width, height, channels;
    };
} // namespace yes
