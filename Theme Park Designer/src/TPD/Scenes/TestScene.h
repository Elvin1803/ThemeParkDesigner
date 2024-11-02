#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include "Core/Scene/Scene.h"

namespace TPD
{

    class TestScene : public Scene
    {
    public:
        TestScene() 
            : Scene() 
        {};

        void Init() override;
        void Update(float deltaTime) override;
    };

}

#endif /* TEST_SCENE_H */