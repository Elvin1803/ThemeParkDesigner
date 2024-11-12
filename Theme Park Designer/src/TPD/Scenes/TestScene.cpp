#include "pch.h"
#include "TestScene.h"

#include "Core/ECS/Components.h"
#include "Core/ECS/Systems.h"
#include "Core/Graphics/GraphicsAPI.h"
#include "Core/Graphics/Models/ModelLoader/ModelLoader.h"

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
        camTransform.SetPosition(glm::vec3(0, 0, 6));

        //Graphics::ModelLoader::LoadFromFile("car.obj");
        Graphics::ModelLoader::LoadFromFile("fish.obj");

        const auto fishMesh = m_registry.create();
        m_registry.emplace<ECS::TagComponent>(fishMesh, "Fish mesh");
        m_registry.emplace<ECS::TransformComponent>(fishMesh);
        m_registry.emplace<ECS::ModelComponent>(fishMesh, m_modelManager.GetResourceID("fish"));
        auto& fishTransform = m_registry.get<ECS::TransformComponent>(fishMesh);
        fishTransform.SetRotation(glm::vec3(0, 90, 0));

        /*
        const auto carMesh = m_registry.create();
        m_registry.emplace<ECS::TagComponent>(carMesh, "Car mesh");
        m_registry.emplace<ECS::TransformComponent>(carMesh);
        m_registry.emplace<ECS::ModelComponent>(carMesh, m_modelManager.GetResourceID("car"));
        auto& carTransform = m_registry.get<ECS::TransformComponent>(carMesh);
        carTransform.SetPosition(glm::vec3(-5, 0, 0));
        */
    }

    void TestScene::Update(float deltaTime)
    {
        /*
        auto squareView = m_registry.view<ECS::TransformComponent, ECS::ModelComponent>();
        for (auto entity : squareView)
        {
            auto& squareTransform = squareView.get<ECS::TransformComponent>(entity);
            squareTransform.SetRotation(glm::vec3(squareTransform.rotation.x, squareTransform.rotation.y - 2, squareTransform.rotation.z));
        }

        auto camView = m_registry.view<ECS::TransformComponent, ECS::CameraComponent>();
        for (auto entity : camView)
        {
            auto& camTransform = camView.get<ECS::TransformComponent>(entity);
            //camTransform.SetPosition(glm::vec3(camTransform.position.x, camTransform.position.y, camTransform.position.z + 0.1f));
            camTransform.SetRotation(glm::vec3(camTransform.rotation.x, camTransform.rotation.y + 1, camTransform.rotation.z));
        }
        */
    }

}