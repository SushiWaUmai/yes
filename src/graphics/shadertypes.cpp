#include "../core.h"

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

            case ShaderDataType::V1F:
                return sizeof(float);
            case ShaderDataType::V2F:
                return sizeof(glm::vec2);
            case ShaderDataType::V3F:
                return sizeof(glm::vec3);
            case ShaderDataType::V4F:
                return sizeof(glm::vec4);

            case ShaderDataType::V1I:
                return sizeof(int);
            case ShaderDataType::V2I:
                return sizeof(glm::ivec2);
            case ShaderDataType::V3I:
                return sizeof(glm::ivec3);
            case ShaderDataType::V4I:
                return sizeof(glm::ivec4);

            case ShaderDataType::V1U:
                return sizeof(unsigned int);
            case ShaderDataType::V2U:
                return sizeof(glm::uvec2);
            case ShaderDataType::V3U:
                return sizeof(glm::uvec3);
            case ShaderDataType::V4U:
                return sizeof(glm::uvec4);

            case ShaderDataType::M3F:
                return sizeof(glm::mat3);
            case ShaderDataType::M4F:

                return sizeof(glm::mat4);
            case ShaderDataType::BOOL:
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

            case ShaderDataType::V1F:
                return GL_FLOAT;
            case ShaderDataType::V2F:
                return GL_FLOAT;
            case ShaderDataType::V3F:
                return GL_FLOAT;
            case ShaderDataType::V4F:
                return GL_FLOAT;

            case ShaderDataType::V1I:
                return GL_INT;
            case ShaderDataType::V2I:
                return GL_INT;
            case ShaderDataType::V3I:
                return GL_INT;
            case ShaderDataType::V4I:
                return GL_INT;

            case ShaderDataType::V1U:
                return GL_UNSIGNED_INT;
            case ShaderDataType::V2U:
                return GL_UNSIGNED_INT;
            case ShaderDataType::V3U:
                return GL_UNSIGNED_INT;
            case ShaderDataType::V4U:
                return GL_UNSIGNED_INT;

            case ShaderDataType::M3F:
                return GL_FLOAT;
            case ShaderDataType::M4F:
                return GL_FLOAT;

            case ShaderDataType::BOOL:
                return GL_BOOL;
            }

            return GL_NONE;
        }

        GLuint ShaderDataTypeToComponentCount(ShaderDataType type)
        {
            switch (type)
            {
            case ShaderDataType::None:
                return 0;

            case ShaderDataType::V1F:
                return 1;
            case ShaderDataType::V2F:
                return 2;
            case ShaderDataType::V3F:
                return 3;
            case ShaderDataType::V4F:
                return 4;

            case ShaderDataType::V1I:
                return 1;
            case ShaderDataType::V2I:
                return 2;
            case ShaderDataType::V3I:
                return 3;
            case ShaderDataType::V4I:
                return 4;

            case ShaderDataType::V1U:
                return 1;
            case ShaderDataType::V2U:
                return 2;
            case ShaderDataType::V3U:
                return 3;
            case ShaderDataType::V4U:
                return 4;

            case ShaderDataType::M3F:
                return 9;
            case ShaderDataType::M4F:
                return 16;

            case ShaderDataType::BOOL:
                return 1;
            }

            return 0;
        }
    }
}
