#ifndef RENDERER_SYSTEM_H
#define RENDERER_SYSTEM_H

#include <entt/entt.hpp>

namespace TPD::ECS::RendererSystem
{
    void update(entt::registry& reg, float deltaTime);
}

#endif /* RENDERER_SYSTEM */