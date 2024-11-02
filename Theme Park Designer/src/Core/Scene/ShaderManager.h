#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H

#include <Core/Graphics/Shaders/Shader.h>

namespace TPD
{

    class ShaderManager
    {
    public:
        ShaderManager() = default;
        ~ShaderManager() = default;

        void InitShader(const char* name, const char* vertexCode, const char* fragmentCode);

        Graphics::Shader* GetShader(const char* name);

    private:
        std::unordered_map<std::string, std::unique_ptr<Graphics::Shader>> m_shaderMap;
    };

}

#endif /* SHADER_MANAGER_H */