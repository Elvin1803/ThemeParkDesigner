#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include <glad/glad.h>

namespace TPD::Graphics
{
    namespace Shaders
    {
        inline const char* basicVert =
#include "Basic.vert"
                ;

        inline const char* basicFrag =
#include "Basic.frag"
                ;
    }

    class ShaderProgram
    {
    public:
        ShaderProgram(const char* vertexCode, const char* fragmentCode);
        ~ShaderProgram();

        inline uint32_t GetID() const { return m_shaderProgramID; };

        void UseShader() const;

    private:
        uint32_t m_shaderProgramID;
    };

}

#endif /* SHADER_PROGRAM_H */