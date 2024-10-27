#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <string>
#include <glm/glm.hpp>

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
        bool isModelDirty = true;

        void SetPosition(const glm::vec3& newPosition) {
            if (position != newPosition)
            {
                position = newPosition;
                isModelDirty = true;
            }
        }

        void SetRotation(const glm::vec3& newRotation) {
            if (rotation != newRotation)
            {
                rotation = newRotation;
                isModelDirty = true;
            }
        }

        void SetScale(const glm::vec3& newScale) {
            if (scale != newScale)
            {
                scale = newScale;
                isModelDirty = true;
            }
        }
    };

    struct CameraComponent
    {
        enum class projectionMode
        {
            PERSPECTIVE,
            OTHOGRAPHIC
        };
        struct viewportRect
        {
            uint32_t x;
            uint32_t y;
            uint32_t width;
            uint32_t height;
        };

        projectionMode projection = projectionMode::PERSPECTIVE;
        float FOV = 70;
        float nearPlane = 0.1f;
        float farPlane = 1000.0f;

        viewportRect m_viewportRect;

        glm::mat4 projectionMatrix = glm::mat4(1.0f);
        bool isProjectionDirty = true;
        glm::mat4 viewMatrix = glm::mat4(1.0f);
        bool isViewDirty = true;
    };

    struct MeshComponent
    {
        // Look into a MeshManager that will get the VAO based on the meshID
        uint32_t meshID;
    };
}

#endif /* COMPONENTS_H */