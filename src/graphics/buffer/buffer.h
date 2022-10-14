#pragma once
#include <GLFW/glfw3.h>
#include "core/ref.h"
#include "graphics/shader/shaderdata.h"

namespace yes
{
    template <GLenum BufferType>
    class Buffer
    {
    public:
        Buffer() = default;
        Buffer(GLsizei count, ShaderDataType type, const void *data, GLenum usage);
        ~Buffer();

        static Ref<Buffer<BufferType>> Create(GLsizei count, ShaderDataType type, const void *data, GLenum usage);

        void Init(GLsizei count, ShaderDataType type, const void *data, GLenum usage);
        void Delete() const;

        void Bind() const;
        void Unbind() const;

        inline GLuint GetID() const { return id; }
        inline GLuint GetCount() const { return count; }
        inline ShaderDataType GetType() const { return dataType; }

        explicit operator GLuint() const { return id; }
    private:
        GLuint id;
        GLsizei count;
        ShaderDataType dataType;
    };
} // namespace yes
