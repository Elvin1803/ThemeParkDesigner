#ifndef PERSPECTIVE_CAMERA_H
#define PERSPECTIVE_CAMERA_H

#include "Camera.h"

namespace TPD::Graphics
{

    class PerspectiveCamera : public Camera
    {
    public:
        PerspectiveCamera(viewportRect& r);

        void SetFOV(float fov);
        void SetPosition(glm::vec3& position);
        void SetRotation(glm::vec3& rotation);

        void UpdateProjection();

    private:
        float m_FOV = 45.0f;
        float m_nearPlane = 0.1f;
        float m_farPlane = 1000.0f;

        glm::vec3 m_position;
        glm::vec3 m_rotation;
    };

}

#endif /* PERSPECTIVE_CAMERA_H */