#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <glm/glm.hpp>

#include <Core/Scene/SceneManager.h>

namespace TPD::ECS
{
    struct TagComponent
    {
        std::string tag = "";

        TagComponent() = default;
        TagComponent(const std::string& tag)
            : tag(tag)
        {
        }
    };

    struct TransformComponent
    {
        glm::vec3 position = { 0.0f, 0.0f, 0.0f };
        glm::vec3 rotation = { 0.0f, 0.0f, 0.0f };
        glm::vec3 scale = { 1.0f, 1.0f, 1.0f };

        glm::mat4 modelMatrix = glm::mat4(1.0f);
        bool isDirty = true;

        void SetPosition(const glm::vec3& newPosition)
        {
            position = newPosition;
            isDirty = true;
        }

        void SetRotation(const glm::vec3& newRotation)
        {
            rotation = newRotation;
            isDirty = true;
        }

        void SetScale(const glm::vec3& newScale)
        {
            scale = newScale;
            isDirty = true;
        }
    };

    struct CameraComponent
    {
        enum class ProjectionMode
        {
            PERSPECTIVE,
            ORTHOGRAPHIC
        };
        struct ViewportRect
        {
            uint32_t x;
            uint32_t y;
            uint32_t width;
            uint32_t height;
        };

        ProjectionMode projection = ProjectionMode::PERSPECTIVE;
        float FOV = 70;
        const float nearPlane = 0.1f;
        const float farPlane = 1000.0f;
        ViewportRect viewportRect;

        glm::mat4 projectionMatrix = glm::mat4(1.0f);
        bool isProjectionDirty = true;
        glm::mat4 viewMatrix = glm::mat4(1.0f);

        CameraComponent() = delete; // Cannot create a camera without a viewport
        CameraComponent(ViewportRect& viewport)
            : viewportRect(viewport)
        {
        }

        void SetProjection(const ProjectionMode proj)
        {
            projection = proj;
            isProjectionDirty = true;
        }

        void SetFOV(const float fov)
        {
            FOV = fov;
            isProjectionDirty = true;
        }

        void SetViewport(ViewportRect& viewport)
        {
            viewportRect = viewport;
            isProjectionDirty = true;
        }
    };

    struct ModelComponent
    {
        uint32_t modelID;
    };
}

#endif /* COMPONENTS_H */