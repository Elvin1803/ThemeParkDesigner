#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Scene.h"

namespace TPD
{

    class SceneManager
    {
    public:
        static void ChangeScene(std::unique_ptr<TPD::Scene> scene);
        static inline TPD::Scene* GetScene() { return m_currentScene.get(); };

    private:
        static std::unique_ptr<TPD::Scene> m_currentScene;
    };

}

#endif /* SCENE_MANAGER_H */