#include "pch.h"
#include "Shader.h"

namespace TPD::Graphics
{
    namespace ShaderSource
    {
        std::unordered_map<std::string, const char*> vertexShaders = {
            {"Basic", R"(

        #version 330 core

        layout (location = 0) in vec3 aPos;
        layout (location = 1) in vec4 aColor;

        uniform mat4 mvp;

        out vec4 outColor;

        void main()
        {
            gl_Position = mvp * vec4(aPos.x, aPos.y, aPos.z, 1.0);
            outColor = aColor;
        }
        )"}
        };

        std::unordered_map<std::string, const char*> fragmentShaders = {
            {"Basic", R"(

        #version 330 core

        in vec4 outColor;

        out vec4 FragColor;

        void main()
        {
            FragColor = outColor;
        }
        )"}
        };
    }

    Shader::Shader(const std::string& vertexScr, const std::string& fragmentSrc)
    {
        // Vertex shader
        uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
        auto vertexCode = ShaderSource::vertexShaders.find(vertexScr);

        glShaderSource(vertexShader, 1, &vertexCode->second, nullptr);
        glCompileShader(vertexShader);
        // check for shader compile errors
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        // Fragment shader
        uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        auto fragmentCode = ShaderSource::fragmentShaders.find(fragmentSrc);

        glShaderSource(fragmentShader, 1, &fragmentCode->second, nullptr);
        glCompileShader(fragmentShader);
        // check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        // Create shader program
        m_shaderProgramID = glCreateProgram();
        glAttachShader(m_shaderProgramID, vertexShader);
        glAttachShader(m_shaderProgramID, fragmentShader);
        glLinkProgram(m_shaderProgramID);

        // Clean up
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    Shader::~Shader()
    {
        glDeleteProgram(m_shaderProgramID);
    }

    void Shader::UseShader() const
    {
        glUseProgram(m_shaderProgramID);
    }

}
