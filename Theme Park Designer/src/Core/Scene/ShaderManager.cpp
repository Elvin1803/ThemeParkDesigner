#include "pch.h"
#include "ShaderManager.h"

#include "Core/Graphics/GraphicsAPI.h"

namespace TPD
{

    void ShaderManager::InitShader(const char* name, const char* vertexCode, const char* fragmentCode)
    {
        auto shader = Graphics::API::CreateShader(vertexCode, fragmentCode);
        m_shaderMap[name] = std::move(shader);
    }

    Graphics::Shader* ShaderManager::GetShader(const char* name)
    {
        return m_shaderMap.at(name).get();
    }

}