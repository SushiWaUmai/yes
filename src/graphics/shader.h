#pragma once
#include <glad/glad.h>

namespace yes
{
    class Shader
    {
    public:
        void Init(const char *vertPath, const char *fragPath);

        void Use() const;
        void Unuse() const;

        inline GLuint GetID() const { return id; }

    private:
        GLuint id;

        bool Compile(GLuint &shader, const char *path);
        bool Link(GLuint vertID, GLuint fragID);
    };
}
