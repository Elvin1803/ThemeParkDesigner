#ifndef SYSTEMS_H
#define SYSTEMS_H

#include "Systems/CameraSystem.h"
#include "Systems/RendererSystem.h"
#include "Systems/TransformSystem.h"

namespace TPD::ECS
{

    class Systems
    {
    public:
        static void Update(float deltaTime, entt::registry& registry);

    private:
        static std::vector<std::function<void(entt::registry& reg, float deltaTime)>> m_systems;
    };

}

#endif /* SYSTEMS */