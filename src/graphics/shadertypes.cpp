#include "yes/yes.h"

namespace yes
{
    namespace ShaderDataTypeUtils
    {
        GLsizei ShaderDataTypeToSize(ShaderDataType type)
        {
            switch (type)
            {
            case ShaderDataType::None:
                return 0;
            case ShaderDataType::Float:
                return sizeof(float);
            case ShaderDataType::Vec2:
                return sizeof(glm::vec2);
            case ShaderDataType::Vec3:
                return sizeof(glm::vec3);
            case ShaderDataType::Vec4:
                return sizeof(glm::vec4);
            case ShaderDataType::Mat3:
                return sizeof(glm::mat3);
            case ShaderDataType::Mat4:
                return sizeof(glm::mat4);
            case ShaderDataType::Int:
                return sizeof(int);
            case ShaderDataType::Int2:
                return sizeof(glm::ivec2);
            case ShaderDataType::Int3:
                return sizeof(glm::ivec3);
            case ShaderDataType::Int4:
                return sizeof(glm::ivec4);
            case ShaderDataType::Bool:
                return sizeof(bool);
            }

            return 0;
        }

        GLenum ShaderDataTypeToGLType(ShaderDataType type)
        {
            switch (type)
            {
            case ShaderDataType::None:
                return GL_NONE;
            case ShaderDataType::Float:
                return GL_FLOAT;
            case ShaderDataType::Vec2:
                return GL_FLOAT;
            case ShaderDataType::Vec3:
                return GL_FLOAT;
            case ShaderDataType::Vec4:
                return GL_FLOAT;
            case ShaderDataType::Mat3:
                return GL_FLOAT;
            case ShaderDataType::Mat4:
                return GL_FLOAT;

            case ShaderDataType::Int:
                return GL_INT;
            case ShaderDataType::Int2:
                return GL_INT;
            case ShaderDataType::Int3:
                return GL_INT;
            case ShaderDataType::Int4:
                return GL_INT;
            case ShaderDataType::Bool:
                return GL_BOOL;
            }

            return GL_NONE;
        }
    }
}