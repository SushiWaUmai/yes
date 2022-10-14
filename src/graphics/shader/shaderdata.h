#pragma once
#include <GLFW/glfw3.h>

namespace yes
{
    enum ShaderDataType
    {
        None = 0,
        V1F,
        V2F,
        V3F,
        V4F,
        V1I,
        V2I,
        V3I,
        V4I,
        V1U,
        V2U,
        V3U,
        V4U,
        M3F,
        M4F,
        BOOL,
        SHADER_DATA_TYPE_COUNT
    };

    namespace ShaderDataTypeUtils
    {
        GLsizei ToSize(ShaderDataType type);
        GLenum ToGLType(ShaderDataType type);
        GLuint ToComponentCount(ShaderDataType type);
    }
}
