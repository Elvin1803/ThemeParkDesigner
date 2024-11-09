#ifndef MESH_H
#define MESH_H

#include "Core/Graphics/Buffers/VertexArray.h"
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>

namespace TPD::Graphics
{

    class Mesh
    {
    public:
        Mesh(std::unique_ptr<VertexArray> vao)
            : m_vao(std::move(vao))
        {
        }
        ~Mesh() = default;

        inline const VertexArray* GetVAO() { return m_vao.get(); };
        const glm::mat4& GetLocalTransform();

        void SetLocalPosition(const glm::vec3& newPosition)
        {
            m_localPosition = newPosition;
            m_isDirty = true;
        }

        void SetLocalRotation(const glm::vec3& newRotation)
        {
            m_localRotation = newRotation;
            m_isDirty = true;
        }

        void SetLocalScale(const glm::vec3& newScale)
        {
            m_localScale = newScale;
            m_isDirty = true;
        }

    private:
        std::unique_ptr<VertexArray> m_vao = nullptr;

        glm::vec3 m_localPosition = { 0, 0, 0 };
        glm::vec3 m_localRotation = { 0, 0, 0 };
        glm::vec3 m_localScale = { 1, 1, 1 };

        glm::mat4 m_transformMatrix = glm::mat4(1.0f);
        bool m_isDirty = true;
    };

}

#endif /* MESH_H */