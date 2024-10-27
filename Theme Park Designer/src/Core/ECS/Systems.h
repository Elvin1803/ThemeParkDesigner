#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <vector>
#include <functional>

#include "Systems/TransformSystem.h"

namespace TPD::ECS
{

    class Systems
    {
    public:
        Systems(entt::registry& m_registry);

        void addSystem(std::function<void(entt::registry& reg, float deltaTime)> system);
        void Update(float deltaTime);

    private:
        std::vector<std::function<void(entt::registry& reg, float deltaTime)>> m_systems;
        entt::registry& m_registry;
    };

}

#endif /* SYSTEMS */