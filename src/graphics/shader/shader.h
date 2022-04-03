#pragma once
#include <vector>

namespace yes
{
    class Shader
    {
    public:
        Shader();
        ~Shader();

        static Ref<Shader> Create();

        void Init();
        void Load(const char *vertPath, const char *fragPath);
        void Delete() const;

        void Use() const;
        void Unuse() const;

        template <GLenum ShaderType>
        void AddSource(Ref<ShaderSource<ShaderType>> source);
        
        template <GLenum ShaderType>
        void RemoveSource(Ref<ShaderSource<ShaderType>> source);

        bool Link();

        void DispatchCompute(int x, int y, int z);

        GLint GetUniformLocation(const char *name);

        // Uniforms
        void SetUniformV1F(const char *name, float value);
        void SetUniformV2F(const char *name, glm::vec2 value);
        void SetUniformV3F(const char *name, glm::vec3 value);
        void SetUniformV4F(const char *name, glm::vec4 value);
        void SetUniformV1I(const char *name, int value);
        void SetUniformV2I(const char *name, glm::ivec2 value);
        void SetUniformV3I(const char *name, glm::ivec3 value);
        void SetUniformV4I(const char *name, glm::ivec4 value);
        void SetUniformV1U(const char *name, unsigned int value);
        void SetUniformV2U(const char *name, glm::uvec2 value);
        void SetUniformV3U(const char *name, glm::uvec3 value);
        void SetUniformV4U(const char *name, glm::uvec4 value);
        void SetUniformM3F(const char *name, glm::mat3 value);
        void SetUniformM4F(const char *name, glm::mat4 value);
        void SetUniformBOOL(const char *name, bool value);

        inline GLuint GetID() const { return id; }

    private:
        GLuint id;
    };
} // namespace yes
