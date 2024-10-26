#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <string>
#include <glm/glm.hpp>

namespace TPD::ECS::Components
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
        glm::vec3 scale = { 1.0f, 1.0f, 1.0f };;
        glm::mat4 modelMatrix = glm::mat4(1.0f);
        bool isDirty = false;

        void SetPosition(const glm::vec3& newPosition) {
            if (position != newPosition)
            {
                position = newPosition;
                isDirty = true;
            }
        }

        void SetRotation(const glm::vec3& newRotation) {
            if (rotation != newRotation)
            {
                rotation = newRotation;
                isDirty = true;
            }
        }

        void SetScale(const glm::vec3& newScale) {
            if (scale != newScale)
            {
                scale = newScale;
                isDirty = true;
            }
        }
    };

    struct MeshComponent
    {
        // Look into a MeshManager that will get the VAO based on the meshID
        uint32_t meshID;
    };
}

#endif /* COMPONENTS_H */