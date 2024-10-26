#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

namespace TPD::Graphics
{

    struct viewportRect
    {
    public:
        uint32_t x;
        uint32_t y;
        uint32_t width;
        uint32_t height;
    };

    class Camera
    {
    public:
        Camera(viewportRect& r)
            : m_viewportRect(r)
        {};
        virtual ~Camera() = default;

        inline glm::mat4 getProjection() const { return m_projection; }
        inline viewportRect GetViewportRect() const { return m_viewportRect; }
        inline float GetAspectRatio() const { return float(m_viewportRect.width) / float(m_viewportRect.height); }

    protected:
        viewportRect m_viewportRect;
        glm::mat4 m_projection = glm::mat4(1.0f);
    };

}

#endif /* CAMERA_H */