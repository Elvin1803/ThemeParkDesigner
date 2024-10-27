#include "pch.h"
#include "TransformSystem.h"


#include "Core/ECS/Components.h"

namespace TPD::ECS::TransformSystem
{
    void update(entt::registry& reg, float deltaTime)
    {
        auto view = reg.view<TPD::ECS::TransformComponent>();

        for (auto entity : view)
        {
            auto transform = view.get<TPD::ECS::TransformComponent>(entity);
            if (transform.isModelDirty)
            {
                std::cout << "Updating modelMatrix" << std::endl;
            }
            else
            {
                std::cout << "Not updating modelMatrix" << std::endl;
            }
        }
    }
}