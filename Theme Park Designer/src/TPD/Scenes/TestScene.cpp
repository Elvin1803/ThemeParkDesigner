#include "pch.h"
#include "TestScene.h"

#include "Core/ECS/Components.h"

namespace TPD
{

    void TestScene::Init()
    {
        const auto mainCamera = m_registry.create();
        m_registry.emplace<ECS::TagComponent>(mainCamera, "Main camera");
        m_registry.emplace<ECS::TransformComponent>(mainCamera);
        ECS::CameraComponent::ViewportRect viewport = { 0, 0, 1280, 720 };
        m_registry.emplace<ECS::CameraComponent>(mainCamera, viewport);
    }

    void TestScene::Update()
    {
        m_systems->Update(0.1f);
    }

}