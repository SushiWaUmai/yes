#include "core.h"
#include "texture.h"
#include <cassert>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace yes
{
    Texture::Texture(const char *path)
    {
        Init(path);
    }

    Texture::Texture(int width, int height, int channels, void *data)
    {
        Init(width, height, channels, data);
    }

    Texture::~Texture()
    {
        Delete();
    }

    Ref<Texture> Texture::Create(const char *path)
    {
        return CreateRef<Texture>(path);
    }

    Ref<Texture> Texture::Create(int width, int height, int channels, void *data)
    {
        return CreateRef<Texture>(width, height, channels, data);
    }

    void Texture::Init(int width, int height, int channels, void *data)
    {
        // generate texture
        glGenTextures(1, &id);
        Bind();

        GLint internalFormat;
        GLenum format;

        switch (channels)
        {
        case 1:
            internalFormat = GL_RED;
            format = GL_RED;
            break;
        case 2:
            internalFormat = GL_RG;
            format = GL_RG;
            break;
        case 3:
            internalFormat = GL_RGB;
            format = GL_RGB;
            break;
        case 4:
            internalFormat = GL_RGBA;
            format = GL_RGBA;
            break;
        default:
            assert(false);
            break;
        }

        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        Unbind();
    }

    void Texture::Init(const char *path)
    {
        // Get the image from path
        unsigned char *data = stbi_load(path, &width, &height, &channels, 0);

        // Check if the image was loaded successfully
        if (!data)
        {
            Logger::Error(CORE_LOGGER, "[IO] Failed to load image: {0}\n{1}", path, stbi_failure_reason());
            return;
        }

        Init(width, height, channels, data);

        // Free the image
        stbi_image_free(data);
    }

    void Texture::Delete() const
    {
        glDeleteTextures(1, &id);
    }

    void Texture::Bind() const
    {
        glBindTexture(GL_TEXTURE_2D, id);
    }

    void Texture::Unbind() const
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
} // namespace yes