#include "../core.h"
#include <iostream>

namespace yes
{
    Ref<Shader> Shader::Create(const char *vertPath, const char *fragPath)
    {
        Ref<Shader> result = CreateRef<Shader>();
        result->Init(vertPath, fragPath);
        return result;
    }

    void Shader::Init(const char *vertPath, const char *fragPath)
    {
        id = glCreateProgram();
        
        GLuint vertID = glCreateShader(GL_VERTEX_SHADER);
        Compile(vertID, vertPath);
        GLuint fragID = glCreateShader(GL_FRAGMENT_SHADER);
        Compile(fragID, fragPath);
        Link(vertID, fragID);
    }

    bool Shader::Compile(GLuint &shaderID, const char *path)
    {
        const char *source = load_file(path);

        if(!source)
        {
            std::cout << "Failed to load shader: " << path << std::endl;
            return false;
        }

        glShaderSource(shaderID, 1, &source, NULL);
        glCompileShader(shaderID);

        GLint result;
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);

        if (result == GL_FALSE)
        {
            GLint length;
            glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);
            char *message = (char *)malloc(length * sizeof(char));
            glGetShaderInfoLog(shaderID, length, &length, message);

            std::cout << "Failed to compile vertex shader" << std::endl << message << std::endl;
            free(message);
            return false;
        }

        return true;
    }

    bool Shader::Link(GLuint vertID, GLuint fragID)
    {
        glAttachShader(id, vertID);
        glAttachShader(id, fragID);

        glLinkProgram(id);

        GLint success;
        glGetProgramiv(id, GL_LINK_STATUS, &success);

        if (success == GL_FALSE)
        {
            GLint length;
            glGetProgramiv(id, GL_INFO_LOG_LENGTH, &length);
            char *message = (char *)malloc(length * sizeof(char));
            glGetProgramInfoLog(id, length, &length, message);

            std::cout << "Failed to link shader program" << std::endl << message << std::endl;
            free(message);
            return false;
        }
        
        return true;
    }

    void Shader::Use() const
    {
        glUseProgram(id);
    }

    void Shader::Unuse() const
    {
        glUseProgram(0);
    }
}
