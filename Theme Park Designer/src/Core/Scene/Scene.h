#ifndef SCENE_H
#define SCENE_H

#include <entt/entt.hpp>

#include "Core/ECS/Systems.h"
#include "Core/Graphics/Models/Model.h"
#include "Core/Graphics/Models/Material.h"
#include "Core/Graphics/Shaders/ShaderProgram.h"

#include "ResourceManager.hxx"

namespace TPD
{
    using ModelManager = ResourceManager<Graphics::Model>;
    using MaterialManager = ResourceManager<Graphics::Material>;
    using ShaderManager = ResourceManager<Graphics::ShaderProgram>;

    class Scene
    {
    public:
        Scene() = default;
        ~Scene() = default;

        virtual void Init() = 0;
        virtual void Update(float deltaTime) = 0;

        inline entt::registry& GetRegistry() { return m_registry; };

        inline ModelManager& GetModelManager() { return m_modelManager; };
        inline MaterialManager& GetMaterialManager() { return m_materialManager; };
        inline ShaderManager& GetShaderManager() { return m_shaderManager; };

    protected:
        entt::registry m_registry;

        ModelManager m_modelManager;
        MaterialManager m_materialManager;
        ShaderManager m_shaderManager;
    };

}

#endif /* SCENE_H */