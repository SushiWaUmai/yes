#include "core.h"

namespace yes
{
    Shader::Shader()
    {
        Init();
    }

    Shader::~Shader()
    {
        Delete();
    }

    Ref<Shader> Shader::Create()
    {
        return CreateRef<Shader>();
    }

    void Shader::Init()
    {
        id = glCreateProgram();
    }

    void Shader::Load(const char *vertPath, const char *fragPath)
    {
        Ref<VertexShader> vertSource = VertexShader::Create();
        Ref<FragmentShader> fragSource = FragmentShader::Create();

        vertSource->Load(vertPath);
        fragSource->Load(fragPath);

        AddSource(vertSource);
        AddSource(fragSource);

        Link();
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

    template <GLenum ShaderType>
    void Shader::AddSource(Ref<ShaderSource<ShaderType>> source)
    {
        glAttachShader(id, source->GetID());
    }

    template <GLenum ShaderType>
    void Shader::RemoveSource(Ref<ShaderSource<ShaderType>> source)
    {
        glDetachShader(id, source->GetID());
    }

    bool Shader::Link()
    {
        glLinkProgram(id);

        GLint success;
        glGetProgramiv(id, GL_LINK_STATUS, &success);

        if (!success)
        {
            GLint length;
            glGetProgramiv(id, GL_INFO_LOG_LENGTH, &length);
            char *message = new char[length];
            glGetProgramInfoLog(id, length, &length, message);
            Logger::Error(CORE_LOGGER, "[Shader] Failed to link shader program:\n{}", message);

            delete[] message;
            return false;
        }

        return true;
    }

    GLint Shader::GetUniformLocation(const char *name)
    {
        Use();
        return glGetUniformLocation(id, name);
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
}
