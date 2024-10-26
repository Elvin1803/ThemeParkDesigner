#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include "Core/Scene/Scene.h"

namespace TPD
{

    class TestScene : public Scene
    {
    public:
        void Init() override;
        void Update() override;
    };

}

#endif /* TEST_SCENE_H */