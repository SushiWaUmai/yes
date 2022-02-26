#pragma once

namespace yes
{
    enum ShaderDataType
    {
        None = 0,
        Float,
        Vec2,
        Vec3,
        Vec4,
        Mat3,
        Mat4,
        Int,
        Int2,
        Int3,
        Int4,
        Bool,
    };

    namespace ShaderDataTypeUtils
    {
        GLsizei ShaderDataTypeToSize(ShaderDataType type);
        GLenum ShaderDataTypeToGLType(ShaderDataType type);
    }
}