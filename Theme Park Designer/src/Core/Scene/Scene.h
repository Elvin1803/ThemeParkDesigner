#ifndef SCENE_H
#define SCENE_H

#include <entt/entt.hpp>

#include "Core/ECS/Systems.h"

namespace TPD
{

    class Scene
    {
    public:
        Scene();
        ~Scene();

        virtual void Init() = 0;
        virtual void Update() = 0;

    protected:
        entt::registry m_registry;
        std::unique_ptr<ECS::Systems> m_systems;
    };

}

#endif /* SCENE_H */