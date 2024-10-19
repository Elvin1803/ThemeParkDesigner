#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

namespace TPD
{

    class Camera
    {
    public:
        Camera(const glm::mat4& projection)
            : m_projection(projection)
        {
        }
        virtual ~Camera() = 0;

        inline glm::mat4 getProjection() const { return m_projection; }

    private:
        glm::mat4 m_projection = glm::mat4(1.0f);
    };

}

#endif /* CAMERA_H */