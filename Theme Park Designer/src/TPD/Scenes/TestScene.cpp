#include "pch.h"
#include "TestScene.h"

#include "Core/ECS/Components.h"

namespace TPD
{

    void TestScene::Init()
    {
        // Create a camera
        const auto mainCamera = m_registry.create();
        m_registry.emplace<ECS::TagComponent>(mainCamera, "Main camera");
        m_registry.emplace<ECS::TransformComponent>(mainCamera);
        ECS::CameraComponent::ViewportRect viewport = { 0, 0, 1280, 720 };
        m_registry.emplace<ECS::CameraComponent>(mainCamera, viewport);

        // create a triangle mesh
        const auto triangleMesh = m_registry.create();
        m_registry.emplace<ECS::TagComponent>(triangleMesh, "Triangle mesh");
        m_registry.emplace<ECS::TransformComponent>(triangleMesh);
        m_registry.emplace<ECS::MeshComponent>(triangleMesh, "triangle");
        auto& transform = m_registry.get<ECS::TransformComponent>(triangleMesh);
        transform.SetPosition(glm::vec3(0, 0, -2));
    }

    void TestScene::Update()
    {
        auto view = m_registry.view<ECS::TransformComponent, ECS::MeshComponent>();
        for (auto entity : view)
        {
            auto& transform = view.get<ECS::TransformComponent>(entity);
            transform.SetRotation(glm::vec3(transform.rotation.x, transform.rotation.y + 1, transform.rotation.z));
        }

        m_systems->Update(0.1f);
    }

}