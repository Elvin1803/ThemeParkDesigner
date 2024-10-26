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

        void Update();

    private:
        entt::registry m_registry;
    };

}

#endif /* SCENE_H */