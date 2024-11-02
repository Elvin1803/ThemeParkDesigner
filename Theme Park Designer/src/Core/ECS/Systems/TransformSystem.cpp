#include "pch.h"
#include "TransformSystem.h"

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

#include "Core/ECS/Components.h"

namespace TPD::ECS::TransformSystem
{
    void update(entt::registry& reg, float deltaTime)
    {
        // Only need to update modelMatrix of entities that are gonna be rendered
        auto view = reg.view<TransformComponent, MeshComponent>();

        for (auto entity : view)
        {
            auto& transform = view.get<TransformComponent>(entity);
            if (transform.isDirty)
            {
                TPD_LOG_INFO("Updating modelMatrix");
                transform.modelMatrix = glm::translate(glm::mat4(1.0f), transform.position);
                transform.modelMatrix = glm::rotate(transform.modelMatrix, glm::radians(transform.rotation.x), glm::vec3(1, 0, 0));
                transform.modelMatrix = glm::rotate(transform.modelMatrix, glm::radians(transform.rotation.y), glm::vec3(0, 1, 0));
                transform.modelMatrix = glm::rotate(transform.modelMatrix, glm::radians(transform.rotation.z), glm::vec3(0, 0, 1));
                transform.modelMatrix = glm::scale(transform.modelMatrix, transform.scale);

                transform.isDirty = false;
            }
        }
    }
}