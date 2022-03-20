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

    Texture::~Texture()
    {
        Delete();
    }

    Ref<Texture> Texture::Create(const char *path)
    {
        return CreateRef<Texture>(path);
    }

    void Texture::Init(const char *path)
    {
        // generate texture
        glGenTextures(1, &id);
        Bind();

        // Get the image from path
        unsigned char *data = stbi_load(path, &width, &height, &channels, 0);

        // Assert that the image was loaded successfully
        assert(data);

        // TODO: Add support for more formats
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

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
