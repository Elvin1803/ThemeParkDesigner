#include "pch.h"
#include "Mesh.h"

#include "Core/Graphics/GraphicsAPI.h"

namespace TPD::Graphics
{

    const glm::mat4& Mesh::GetLocalTransform()
    {
        if (m_isDirty)
        {
            glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), m_localPosition);
            glm::vec3 rotationRad = glm::radians(m_localRotation);
            glm::quat quaternion = glm::quat(rotationRad);
            glm::mat4 rotationMatrix = glm::toMat4(quaternion);
            glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), m_localScale);

            m_transformMatrix = translationMatrix * rotationMatrix * scaleMatrix;
            m_isDirty = false;
        }

        return m_transformMatrix;
    }

}