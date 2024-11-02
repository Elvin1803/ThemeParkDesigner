#ifndef SCENE_H
#define SCENE_H

#include <entt/entt.hpp>

#include "Core/ECS/Systems.h"
#include "MeshManager.h"
#include "ShaderManager.h"

namespace TPD
{

    class Scene
    {
    public:
        Scene() = default;
        ~Scene() = default;

        virtual void Init() = 0;
        virtual void Update(float deltaTime) = 0;

        inline entt::registry& GetRegistry() { return m_registry; };
        inline MeshManager& GetMeshManager() { return m_meshManager; };
        inline ShaderManager& GetShaderManager() { return m_shaderManager; };

    protected:
        entt::registry m_registry;
        MeshManager m_meshManager;
        ShaderManager m_shaderManager;
    };

}

#endif /* SCENE_H */