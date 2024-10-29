#include "pch.h"
#include "Systems.h"

namespace TPD::ECS
{
    Systems::Systems(entt::registry& reg)
        : m_registry(reg)
    {
        addSystem(ECS::TransformSystem::update);
        addSystem(ECS::CameraSystem::update);
        addSystem(ECS::RendererSystem::update);
    }

    void Systems::addSystem(std::function<void(entt::registry& reg, float deltaTime)> system)
    {
        m_systems.push_back(system);
    }

    void Systems::Update(float deltaTime)
    {
        for (auto& system : m_systems)
        {
            system(m_registry, deltaTime);
        }
    }

}