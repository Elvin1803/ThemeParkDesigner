#include "pch.h"
#include "CameraSystem.h"

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/string_cast.hpp>

#include "Core/ECS/Components.h"

namespace TPD::ECS::CameraSystem
{
    void update(entt::registry& reg, float deltaTime)
    {
        // Update the viewMatrix and projectionMatrix of cameras that have a transform component
        auto view = reg.view<TPD::ECS::TransformComponent, TPD::ECS::CameraComponent>();

        for (auto entity : view)
        {
            auto& [transform, camera] = view.get<TPD::ECS::TransformComponent, TPD::ECS::CameraComponent>(entity);
            if (transform.isDirty)
            {
                std::cout << "Updating viewMatrix" << std::endl;
                glm::vec3 rotationRad = glm::radians(transform.rotation);
                glm::quat quaternion = glm::quat(rotationRad);
                glm::mat4 rotationMatrix = glm::toMat4(quaternion);
                glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), -transform.position);

                camera.viewMatrix = rotationMatrix * translationMatrix;
                transform.isDirty = false;
            }

            if (camera.isProjectionDirty)
            {
                std::cout << "Updating projectionMatrix" << std::endl;
                if (camera.projection == ECS::CameraComponent::ProjectionMode::OTHOGRAPHIC)
                {
                    camera.projectionMatrix = glm::mat4(1.0f);
                }
                else
                {
                    camera.projectionMatrix = glm::perspective(glm::radians(camera.FOV), ((float)camera.viewportRect.height / (float)camera.viewportRect.width), camera.nearPlane, camera.farPlane);
                }
                camera.isProjectionDirty = false;
            }
        }
    }
}