#ifndef TRANSFORM_SYSTEM_H
#define TRANSFORM_SYSTEM_H

#include <entt/entt.hpp>

namespace TPD::ECS::TransformSystem
{
    void update(entt::registry& reg, float deltaTime);
}


#endif /* TRANSFORM_SYSTEM */