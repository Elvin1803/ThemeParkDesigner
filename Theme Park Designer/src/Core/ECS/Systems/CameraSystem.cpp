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
        auto view = reg.view<TransformComponent, CameraComponent>();

        for (auto entity : view)
        {
            const auto& [transform, camera] = view.get<TransformComponent, CameraComponent>(entity);
            if (transform.isDirty)
            {
                glm::vec3 rotationRad = glm::radians(transform.rotation);
                glm::quat quaternion = glm::quat(rotationRad);
                glm::mat4 rotationMatrix = glm::toMat4(quaternion);
                glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), -transform.position);
                camera.viewMatrix = rotationMatrix * translationMatrix;

                TPD_LOG_INFO("Updating viewMatrix: {}", glm::to_string(camera.viewMatrix));
                transform.isDirty = false;
            }

            if (camera.isProjectionDirty)
            {
                float aspectRatio = ((float)camera.viewportRect.width / (float)camera.viewportRect.height);
                if (camera.projection == CameraComponent::ProjectionMode::ORTHOGRAPHIC)
                {
                    camera.projectionMatrix = glm::ortho(-(aspectRatio / 2), (aspectRatio / 2), -1.0f, 1.0f, 0.0f, 1000.0f);
                }
                else
                {
                    camera.projectionMatrix = glm::perspective(glm::radians(camera.FOV), aspectRatio, camera.nearPlane, camera.farPlane);
                }
                TPD_LOG_INFO("Updating projectionMatrix: {}", glm::to_string(camera.projectionMatrix));
                camera.isProjectionDirty = false;
            }
        }
    }
}