#include "pch.h"
#include "Systems.h"

namespace TPD::ECS
{
    std::vector<std::function<void(entt::registry& reg, float deltaTime)>> Systems::m_systems
    {
        ECS::TransformSystem::update,
        ECS::CameraSystem::update,
        ECS::RendererSystem::update
    };

    void Systems::Update(float deltaTime, entt::registry& registry)
    {
        for (auto& system : m_systems)
        {
            system(registry, deltaTime);
        }
    }

}