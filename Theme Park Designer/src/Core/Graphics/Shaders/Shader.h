#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

namespace TPD::Graphics
{

    class Shader
    {
    public:
        Shader(const std::string& vertexScr, const std::string& fragmentSrc);
        ~Shader();

        void UseShader() const;

    private:
        uint32_t m_shaderProgramID;
    };

}

#endif /* SHADER_H */