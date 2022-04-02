#include "core.h"
#include "texture.h"

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

    GLint Texture::GetColorFormat(int channels)
    {
        switch (channels)
        {
        case 1:
            return GL_RED;
        case 2:
            return GL_RG;
        case 3:
            return GL_RGB;
        case 4:
            return GL_RGBA;
        default:
            Logger::Error(CORE_LOGGER, "[Texture] Unsupported number of channels: {}", channels);
            return 0;
        }
    }

    void Texture::Init(int width, int height, int channels, void *data)
    {
        // generate texture
        glGenTextures(1, &id);
        Bind();

        GLenum colorFormat = GetColorFormat(channels);

        glTexImage2D(GL_TEXTURE_2D, 0, colorFormat, width, height, 0, colorFormat, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        this->width = width;
        this->height = height;
        this->channels = channels;

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

    void Texture::Resize(int width, int height)
    {
        Bind();

        GLint colorFormat = GetColorFormat(channels);

        glTexImage2D(GL_TEXTURE_2D, 0, colorFormat, width, height, 0, colorFormat, GL_UNSIGNED_BYTE, nullptr);
        glGenerateMipmap(GL_TEXTURE_2D);

        this->width = width;
        this->height = height;

        Unbind();
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