#include "pch.h"
#include "TransformSystem.h"

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>

#include "Core/ECS/Components.h"

namespace TPD::ECS::TransformSystem
{
    void update(entt::registry& reg, float deltaTime)
    {
        auto view = reg.view<TransformComponent, ModelComponent>();

        for (auto entity : view)
        {
            auto& transform = view.get<TransformComponent>(entity);
            if (transform.isDirty)
            {
                TPD_LOG_INFO("Updating modelMatrix");
                glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), transform.position);
                glm::vec3 rotationRad = glm::radians(transform.rotation);
                glm::quat quaternion = glm::quat(rotationRad);
                glm::mat4 rotationMatrix = glm::toMat4(quaternion);
                glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), transform.scale);

                transform.modelMatrix = translationMatrix * rotationMatrix * scaleMatrix;
                transform.isDirty = false;
            }
        }
    }
}