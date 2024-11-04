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

        // Create Triangle mesh
        float vertices[] = {
            -0.3f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,
            0.3f,  -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 1.0f,
            0.0f,   0.5f, 0.0f,  0.0f, 0.0f, 1.0f, 1.0f,
        };

        uint32_t indices[] = {
            0, 1, 2
        };

        auto layout = Graphics::API::CreateBufferLayout({
                Graphics::API::CreateBufferLayoutElement(3, TPD::Graphics::ShaderDataType::Float), // position
                Graphics::API::CreateBufferLayoutElement(4, TPD::Graphics::ShaderDataType::Float)  // color
            });

        auto vbo = Graphics::API::CreateVertexBuffer(vertices, sizeof(vertices));
        auto ibo = Graphics::API::CreateIndexBuffer(indices, sizeof(indices));
        auto triangle = Graphics::API::CreateVertexArray(layout, std::move(ibo), std::move(vbo));
        this->m_meshManager.PushResource("triangle", std::move(triangle));

        // Create a camera
        const auto mainCamera = m_registry.create();
        m_registry.emplace<ECS::TagComponent>(mainCamera, "Main camera");
        m_registry.emplace<ECS::TransformComponent>(mainCamera);
        ECS::CameraComponent::ViewportRect viewport = { 0, 0, 1280, 720 };
        m_registry.emplace<ECS::CameraComponent>(mainCamera, viewport);
        auto& cam = m_registry.get<ECS::CameraComponent>(mainCamera);
        cam.SetProjection(ECS::CameraComponent::ProjectionMode::ORTHOGRAPHIC);

        // create a triangle mesh
        const auto triangleMesh = m_registry.create();
        m_registry.emplace<ECS::TagComponent>(triangleMesh, "Triangle mesh");
        m_registry.emplace<ECS::TransformComponent>(triangleMesh);
        m_registry.emplace<ECS::MeshComponent>(triangleMesh, m_meshManager.GetResouceID("triangle"));
        auto& transform = m_registry.get<ECS::TransformComponent>(triangleMesh);
        transform.SetPosition(glm::vec3(0, 0, -1));
    }

    void TestScene::Update(float deltaTime)
    {
        auto view = m_registry.view<ECS::TransformComponent, ECS::MeshComponent>();
        for (auto entity : view)
        {
            auto& transform = view.get<ECS::TransformComponent>(entity);
            //transform.SetRotation(glm::vec3(transform.rotation.x, transform.rotation.y, transform.rotation.z + 1));
            //transform.SetPosition(glm::vec3(transform.position.x, transform.position.y, transform.position.z - 0.01f));
        }
    }

}