#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

namespace TPD::Graphics
{

    struct viewportRect
    {
    public:
        float x;
        float y;
        float width;
        float height;
    };

    class Camera
    {
    public:
        Camera(viewportRect& r)
            : m_viewportRect(r)
        {};
        virtual ~Camera() = default;

        inline glm::mat4 getProjection() const { return m_projection; }
        inline float GetAspectRatio() const { return m_viewportRect.width / m_viewportRect.height; }

    protected:
        viewportRect m_viewportRect;
        glm::mat4 m_projection = glm::mat4(1.0f);
    };

}

#endif /* CAMERA_H */