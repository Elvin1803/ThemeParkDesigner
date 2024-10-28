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
        m_registry.emplace<ECS::CameraComponent>(mainCamera);

        m_systems->addSystem(ECS::TransformSystem::update);
        m_systems->addSystem(ECS::CameraSystem::update);
    }

    void TestScene::Update()
    {
        m_systems->Update(0.1f);
    }

}