#pragma once
#include "../core.h"

namespace yes
{
    class Shader
    {
    public:
        static Ref<Shader> Create(const char *vertPath, const char * fragPath);

        void Use() const;
        void Unuse() const;

        inline GLuint GetID() const { return id; }

    private:
        GLuint id;
        void Init(const char *vertPath, const char *fragPath);

        bool Compile(GLuint &shader, const char *path);
        bool Link(GLuint vertID, GLuint fragID);
    };
}
