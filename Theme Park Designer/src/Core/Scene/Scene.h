#ifndef SCENE_H
#define SCENE_H

#include <entt/entt.hpp>

namespace TPD
{

    class Scene
    {
    public:
        Scene();
        ~Scene();

        virtual void Init() = 0;
        virtual void Update() = 0;

    private:
        entt::registry m_registry;
    };

}

#endif /* SCENE_H */