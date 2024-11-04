#ifndef SCENE_H
#define SCENE_H

#include <entt/entt.hpp>

#include "Core/ECS/Systems.h"
#include "Core/Graphics/Buffers/VertexArray.h"
#include "Core/Graphics/Shaders/ShaderProgram.h"

#include "ResourceManager.hxx"

namespace TPD
{
    using MeshManager = ResourceManager<Graphics::VertexArray>;
    using ShaderManager = ResourceManager<Graphics::ShaderProgram>;

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
        MeshManager m_meshManager; // Maybe change to a MeshData later (Don't forget to update code in rendererSystem)
        ShaderManager m_shaderManager;
    };

}

#endif /* SCENE_H */