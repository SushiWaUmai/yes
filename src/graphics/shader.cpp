#include "../core.h"
#include <iostream>

namespace yes
{
    Shader::Shader(const char *vertPath, const char *fragPath)
    {
        Init(vertPath, fragPath);
    }

    Shader::~Shader()
    {
        Delete();
    }

    Ref<Shader> Shader::Create(const char *vertPath, const char *fragPath)
    {
        return CreateRef<Shader>(vertPath, fragPath);
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

    void Shader::Delete() const
    {
        glDeleteProgram(id);
    }

    void Shader::Use() const
    {
        glUseProgram(id);
    }

    void Shader::Unuse() const
    {
        glUseProgram(0);
    }

    void Shader::SetUniformV1F(const char *name, float value) { glUniform1f(GetUniformLocation(name), value); }
    void Shader::SetUniformV2F(const char *name, glm::vec2 value) { glUniform2fv(GetUniformLocation(name), 1, &value[0]); }
    void Shader::SetUniformV3F(const char *name, glm::vec3 value) { glUniform3fv(GetUniformLocation(name), 1, &value[0]); }
    void Shader::SetUniformV4F(const char *name, glm::vec4 value) { glUniform4fv(GetUniformLocation(name), 1, &value[0]); }
    void Shader::SetUniformV1I(const char *name, int value) { glUniform1i(GetUniformLocation(name), value); }
    void Shader::SetUniformV2I(const char *name, glm::ivec2 value) { glUniform2iv(GetUniformLocation(name), 1, &value[0]); }
    void Shader::SetUniformV3I(const char *name, glm::ivec3 value) { glUniform3iv(GetUniformLocation(name), 1, &value[0]); }
    void Shader::SetUniformV4I(const char *name, glm::ivec4 value) { glUniform4iv(GetUniformLocation(name), 1, &value[0]); }
    void Shader::SetUniformV1U(const char *name, unsigned int value) { glUniform1ui(GetUniformLocation(name), value); }
    void Shader::SetUniformV2U(const char *name, glm::uvec2 value) { glUniform2uiv(GetUniformLocation(name), 1, &value[0]); }
    void Shader::SetUniformV3U(const char *name, glm::uvec3 value) { glUniform3uiv(GetUniformLocation(name), 1, &value[0]); }
    void Shader::SetUniformV4U(const char *name, glm::uvec4 value) { glUniform4uiv(GetUniformLocation(name), 1, &value[0]); }
    void Shader::SetUniformM3F(const char *name, glm::mat3 value) { glUniformMatrix3fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]); }
    void Shader::SetUniformM4F(const char *name, glm::mat4 value) { glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]); }
    void Shader::SetUniformBOOL(const char *name, bool value) { glUniform1i(GetUniformLocation(name), (int)value); }

    bool Shader::Compile(GLuint &shaderID, const char *path)
    {
        const char *source = load_file(path);

        if (!source)
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

            std::cout << "Failed to compile vertex shader" << std::endl
                      << message << std::endl;
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

            std::cout << "Failed to link shader program" << std::endl
                      << message << std::endl;
            free(message);
            return false;
        }

        glDeleteShader(vertID);
        glDeleteShader(fragID);

        return true;
    }

    GLint Shader::GetUniformLocation(const char *name)
    {
        Use();
        return glGetUniformLocation(id, name);
    }
}
