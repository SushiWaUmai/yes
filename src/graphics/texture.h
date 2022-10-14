#pragma once
#include <GLFW/glfw3.h>
#include "core/ref.h"

namespace yes
{
    class Texture
    {
    public:
        Texture() = default;
        Texture(int width, int height, int channels, void *data);
        Texture(const char *path);
        ~Texture();

        static Ref<Texture> Create(int width, int height, int channels, void *data);
        static Ref<Texture> Create(const char *path);

        static GLint GetColorFormat(int channels);

        void Init(const char *path);
        void Init(int width, int height, int channels, void *data);
        void Resize(int width, int height);
        void Delete() const;

        void Bind() const;
        void Unbind() const;

        inline GLuint GetID() const { return id; }

    private:
        GLuint id;
        int width, height, channels;
    };
} // namespace yes
