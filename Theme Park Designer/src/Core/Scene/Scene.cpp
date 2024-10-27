#include "pch.h"
#include "Scene.h"

namespace TPD
{
    Scene::Scene()
    {
        m_systems = std::make_unique<ECS::Systems>(m_registry);
    }

    Scene::~Scene()
    {
    }
}