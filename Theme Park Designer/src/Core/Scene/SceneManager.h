#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Scene.h"

namespace TPD
{

    class SceneManager
    {
    public:
        static void ChangeScene(std::unique_ptr<Scene> scene);
        static void Update(float deltaTime)
        {
            m_currentScene->Update(deltaTime);
            ECS::Systems::Update(deltaTime, m_currentScene->GetRegistry());
        };

        static inline Scene* GetScene() { return m_currentScene.get(); };

    private:
        static std::unique_ptr<Scene> m_currentScene;
    };

}

#endif /* SCENE_MANAGER_H */