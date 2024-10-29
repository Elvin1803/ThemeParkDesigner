#include "pch.h"
#include "SceneManager.h"

namespace TPD
{
    std::unique_ptr<Scene> SceneManager::m_currentScene = nullptr;

    void SceneManager::ChangeScene(std::unique_ptr<Scene> scene)
    {
        m_currentScene = std::move(scene);
        m_currentScene->Init();
    }

}