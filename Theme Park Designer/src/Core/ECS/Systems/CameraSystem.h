#ifndef CAMERA_SYSTEM_H
#define CAMERA_SYSTEM_H

#include <entt/entt.hpp>

namespace TPD::ECS::CameraSystem
{
    void update(entt::registry& reg, float deltaTime);
}


#endif /* CAMERA_SYSTEM */