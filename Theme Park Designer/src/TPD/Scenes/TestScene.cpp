#include "pch.h"
#include "TestScene.h"

#include "Core/ECS/Components.h"
#include "Core/ECS/Systems.h"
#include "Core/Graphics/GraphicsAPI.h"

namespace TPD
{

    void TestScene::Init()
    {
        // Create shaders
        auto basicShader = Graphics::API::CreateShader(Graphics::Shaders::basicVert, Graphics::Shaders::basicFrag);
        this->m_shaderManager.PushResource("Basic", std::move(basicShader));

        // Create a camera
        const auto mainCamera = m_registry.create();
        m_registry.emplace<ECS::TagComponent>(mainCamera, "Main camera");
        m_registry.emplace<ECS::TransformComponent>(mainCamera);
        ECS::CameraComponent::ViewportRect viewport = { 0, 0, 1280, 720 };
        m_registry.emplace<ECS::CameraComponent>(mainCamera, viewport);
        //auto& cam = m_registry.get<ECS::CameraComponent>(mainCamera);
        //cam.SetProjection(ECS::CameraComponent::ProjectionMode::ORTHOGRAPHIC);
        auto& camTransform = m_registry.get<ECS::TransformComponent>(mainCamera);
        camTransform.SetPosition(glm::vec3(0, 0, 1));

        // Create square mesh
        auto square = std::make_unique<Graphics::Model>();
        square->LoadFromFile("a");
        this->m_modelManager.PushResource("square", std::move(square));
        // create a square entity
        const auto squareMesh = m_registry.create();
        m_registry.emplace<ECS::TagComponent>(squareMesh, "Square mesh");
        m_registry.emplace<ECS::TransformComponent>(squareMesh);
        m_registry.emplace<ECS::ModelComponent>(squareMesh, m_modelManager.GetResouceID("square"));
    }

    void TestScene::Update(float deltaTime)
    {
        auto squareView = m_registry.view<ECS::TransformComponent, ECS::ModelComponent>();
        for (auto entity : squareView)
        {
            auto& squareTransform = squareView.get<ECS::TransformComponent>(entity);
            squareTransform.SetRotation(glm::vec3(squareTransform.rotation.x, squareTransform.rotation.y, squareTransform.rotation.z + 1));
        }

        auto camView = m_registry.view<ECS::TransformComponent, ECS::CameraComponent>();
        for (auto entity : camView)
        {
            auto& camTransform = camView.get<ECS::TransformComponent>(entity);
            //camTransform.SetPosition(glm::vec3(camTransform.position.x, camTransform.position.y, camTransform.position.z + 0.1f));
            camTransform.SetRotation(glm::vec3(camTransform.rotation.x, camTransform.rotation.y + 1, camTransform.rotation.z));
        }
    }

}